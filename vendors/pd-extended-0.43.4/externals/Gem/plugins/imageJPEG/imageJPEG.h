/*-----------------------------------------------------------------

GEM - Graphics Environment for Multimedia

Load a picture (using libjpeg)

Copyright (c) 2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.


-----------------------------------------------------------------*/

#ifndef _INCLUDE_GEMPLUGIN__IMAGEJPEG_IMAGEJPEG_H_
#define _INCLUDE_GEMPLUGIN__IMAGEJPEG_IMAGEJPEG_H_
#include "plugins/imageBase.h"
#include <stdio.h>

/*-----------------------------------------------------------------
  -------------------------------------------------------------------
  CLASS
  imageJPEG
  
  Loads in a picture
  
  KEYWORDS
  pix
  
  DESCRIPTION

  -----------------------------------------------------------------*/
namespace gem { namespace plugins { 
class GEM_EXPORT imageJPEG : public gem::plugins::imageBase {
 public:

  //////////
  // Constructor
  imageJPEG(void);
  virtual ~imageJPEG(void);

  //////////
  // read an image
  virtual bool load(std::string filename, imageStruct&result, gem::Properties&props);
  //////////
  // write an image
  virtual bool          save(const imageStruct&img, const std::string&filename, const std::string&mimetype, const gem::Properties&props);
  //////////
  // estimate, how well we could save this image
  virtual float estimateSave(const imageStruct&img, const std::string&filename, const std::string&mimetype, const gem::Properties&props);

};
};};

#endif	// for header file
