 /* ------------------------------------------------------------------
  * GEM - Graphics Environment for Multimedia
  *
  *  Copyright (c) 2002-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
  *	zmoelnig@iem.kug.ac.at
  *  For information on usage and redistribution, and for a DISCLAIMER
  *  OF ALL WARRANTIES, see the file, "GEM.LICENSE.TERMS"
  *
  *  this file has been generated...
  * ------------------------------------------------------------------
  */

#ifndef _INCLUDE__GEM_OPENGL_GEMGLLIGHTMODELI_H_
#define _INCLUDE__GEM_OPENGL_GEMGLLIGHTMODELI_H_

#include "Base/GemGLBase.h"

/*
 CLASS
	GEMglLightModeli
 KEYWORDS
	openGL	0
 DESCRIPTION
	wrapper for the openGL-function
	"glLightModeli( GLenum pname, GLint param)"
 */

class GEM_EXTERN GEMglLightModeli : public GemGLBase
{
	CPPEXTERN_HEADER(GEMglLightModeli, GemGLBase);

	public:
	  // Constructor
	  GEMglLightModeli (t_float, t_float);	// CON

	protected:
	  // Destructor
	  virtual ~GEMglLightModeli ();
	  // Do the rendering
	  virtual void	render (GemState *state);

	// variables
	  GLenum	pname;		// VAR
	  virtual void	pnameMess(t_float);	// FUN

	  GLint	param;		// VAR
	  virtual void	paramMess(t_float);	// FUN


	private:

	// we need some inlets
	  t_inlet *m_inlet[2];

	// static member functions
	  static void	 pnameMessCallback (void*, t_floatarg);
	  static void	 paramMessCallback (void*, t_floatarg);
};
#endif // for header file
