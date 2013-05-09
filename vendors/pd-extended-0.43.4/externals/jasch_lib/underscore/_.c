/*__________________________________________________________________________	_     �      (underscore) prepend setter    Copyright � 2002-2006 jan schacher    This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.    This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.    You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA        revision history:    20040303 rebuilt release	20060516 PD-port    ____________________________________________________________________________*/#include "m_pd.h"#define MAXSIZE 1024#define MIN(a,b) ((a)<(b)?(a):(b))typedef struct underscore {	t_object 	ob;	t_atom		p_at[MAXSIZE*2];	int			p_headlength, p_bodylength;	void 		*p_outlet; 		} t_underscore;void *underscore_class;void *underscore_new(t_symbol *s, short ac, t_atom *av);void underscore_bang(t_underscore *x);void underscore_float(t_underscore *x, double f);									void underscore_anything(t_underscore *x, t_symbol *s, short ac, t_atom *av);void underscore_set(t_underscore *x, t_symbol *s, short ac, t_atom *av);void underscore_list(t_underscore *x, t_symbol *s, short ac, t_atom *av);void underscore_output(t_underscore *x);t_symbol *ps_bang;t_symbol *ps_set;void __setup(void){	underscore_class = class_new(gensym("_"), (t_newmethod)underscore_new, 0L, sizeof(t_underscore), 0, A_GIMME, 0);	class_addbang(underscore_class, (t_method)underscore_bang);	class_addfloat(underscore_class, (t_method)underscore_float);	class_addmethod(underscore_class, (t_method)underscore_list,		gensym("list"), A_GIMME, 0);	class_addanything(underscore_class, (t_method)underscore_anything);	class_addmethod(underscore_class, (t_method)underscore_set,		gensym("set"), A_GIMME, 0);	post(".    _    .    jasch    .    "__DATE__" ",0);		ps_bang = gensym("bang");	ps_set = gensym("set");}void *underscore_new(t_symbol *s, short ac, t_atom *av){	t_underscore *x;	int i;	t_atom *at;		x = (t_underscore *)pd_new(underscore_class);	x->p_outlet = outlet_new(&x->ob,0);		at = x->p_at;	x->p_headlength = 1;	x->p_bodylength = 0;	at[0].a_type = A_SYMBOL;	at[0].a_w.w_symbol = ps_set;	 	if(ac != 0){	ac = MIN(MAXSIZE, ac);	x->p_headlength = ac;	for (i=0; i<ac; ++i) *at++ = *av++;	}	return x;}void underscore_bang(t_underscore *x){	t_atom *at;	at = x->p_at;	x->p_bodylength = 1;	x->p_at[x->p_headlength].a_type = A_SYMBOL;	x->p_at[x->p_headlength].a_w.w_symbol = ps_bang;	underscore_output(x) ;}void underscore_float(t_underscore *x, double f){		t_atom *at;	at = x->p_at;	x->p_bodylength = 1;	SETFLOAT(at+(x->p_headlength), f);	underscore_output(x) ;}void underscore_list(t_underscore *x, t_symbol *s, short ac, t_atom *av){	t_atom *at;	int i, temp;		ac = MIN(MAXSIZE, ac);	x->p_bodylength = ac;		// indicates input list length	temp = x->p_headlength;	at = x->p_at;	at = at + temp;				ac = MIN(MAXSIZE, ac);	for (i=0; i<ac; i++) *at++ = *av++;	underscore_output(x) ;}void underscore_anything(t_underscore *x, t_symbol *s, short ac, t_atom *av){	int i, temp;	t_atom *at;		temp = x->p_headlength;		at = x->p_at;	ac = MIN(MAXSIZE-1, ac);	x->p_bodylength = ac+1;			at = x->p_at;	at = at + temp+1;			x->p_at[temp].a_type = A_SYMBOL;	x->p_at[temp].a_w.w_symbol = s;			for (i=(temp+1); i<(ac+temp+1); i++) *at++ = *av++;	underscore_output(x) ;}void underscore_set(t_underscore *x, t_symbol *s, short ac, t_atom *av){		t_atom *at;	int i, temp;		at = x->p_at;	x->p_headlength = ac;		// indicates input list length	ac = MIN(MAXSIZE, ac);	for (i=0; i<ac; i++) *at++ = *av++;}void underscore_output(t_underscore *x){	t_atom *at;	t_atom atoms[MAXSIZE*2];	int i, outlength;	t_symbol *s;		at = x->p_at;	outlength = MIN(MAXSIZE, (x->p_headlength+x->p_bodylength));			if(x->p_at[0].a_type != A_SYMBOL){	outlet_list(x->p_outlet, 0L, outlength, at);	}else{ 		at ++;	s = x->p_at[0].a_w.w_symbol;	outlet_anything(x->p_outlet, s, outlength-1, at);	}}