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

#include "GEMglTexCoord1iv.h"

CPPEXTERN_NEW_WITH_ONE_ARG ( GEMglTexCoord1iv , t_floatarg, A_DEFFLOAT);

/////////////////////////////////////////////////////////
//
// GEMglTexCoord1iv
//
/////////////////////////////////////////////////////////
// Constructor
//
GEMglTexCoord1iv :: GEMglTexCoord1iv	(t_floatarg arg0=0) {
vMess(arg0);
	m_inlet = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("v"));
}
/////////////////////////////////////////////////////////
// Destructor
//
GEMglTexCoord1iv :: ~GEMglTexCoord1iv () {
	inlet_free(m_inlet);
}

/////////////////////////////////////////////////////////
// Render
//
void GEMglTexCoord1iv :: render(GemState *state) {
	glTexCoord1iv (v);
}

/////////////////////////////////////////////////////////
// variable
//
void GEMglTexCoord1iv :: vMess (t_float arg0) {	// FUN
	v[0]=static_cast<GLint>(arg0);
	setModified();
}

/////////////////////////////////////////////////////////
// static member functions
//

void GEMglTexCoord1iv :: obj_setupCallback(t_class *classPtr) {
	 class_addmethod(classPtr, reinterpret_cast<t_method>(&GEMglTexCoord1iv::vMessCallback),  	gensym("v"), A_DEFFLOAT, A_NULL);
}

void GEMglTexCoord1iv :: vMessCallback (void* data, t_floatarg arg0) {
	GetMyClass(data)->vMess ( arg0);
}
