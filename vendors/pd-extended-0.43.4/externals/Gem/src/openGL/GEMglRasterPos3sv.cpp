////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// Implementation file
//
// Copyright (c) 2002-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
//	zmoelnig@iem.kug.ac.at
//  For information on usage and redistribution, and for a DISCLAIMER
//  *  OF ALL WARRANTIES, see the file, "GEM.LICENSE.TERMS"
//
//  this file has been generated...
////////////////////////////////////////////////////////

#include "GEMglRasterPos3sv.h"

CPPEXTERN_NEW_WITH_THREE_ARGS ( GEMglRasterPos3sv , t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT);

/////////////////////////////////////////////////////////
//
// GEMglRasterPos3sv
//
/////////////////////////////////////////////////////////
// Constructor
//
GEMglRasterPos3sv :: GEMglRasterPos3sv	(t_floatarg arg0=0, t_floatarg arg1=0, t_floatarg arg2=0) {
vMess(arg0, arg1, arg2);
	m_inlet = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("v"));
}
/////////////////////////////////////////////////////////
// Destructor
//
GEMglRasterPos3sv :: ~GEMglRasterPos3sv () {
	inlet_free(m_inlet);
}

/////////////////////////////////////////////////////////
// Render
//
void GEMglRasterPos3sv :: render(GemState *state) {
	glRasterPos3sv (v);
}

/////////////////////////////////////////////////////////
// variable
//
void GEMglRasterPos3sv :: vMess (t_float arg0, t_float arg1, t_float arg2) {	// FUN
	v[0]=static_cast<GLshort>(arg0);
	v[1]=static_cast<GLshort>(arg1);
	v[2]=static_cast<GLshort>(arg2);
	setModified();
}

/////////////////////////////////////////////////////////
// static member functions
//

void GEMglRasterPos3sv :: obj_setupCallback(t_class *classPtr) {
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglRasterPos3sv::vMessCallback),  	gensym("v"), A_DEFFLOAT, A_DEFFLOAT, A_DEFFLOAT, A_NULL);
}

void GEMglRasterPos3sv :: vMessCallback (void* data, t_floatarg arg0, t_floatarg arg1, t_floatarg arg2) {
	GetMyClass(data)->vMess ( arg0, arg1, arg2);
}
