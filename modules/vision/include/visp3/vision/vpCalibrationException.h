/****************************************************************************
 *
 * ViSP, open source Visual Servoing Platform software.
 * Copyright (C) 2005 - 2023 by Inria. All rights reserved.
 *
 * This software is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ViSP with software that can not be combined with the GNU
 * GPL, please contact Inria about acquiring a ViSP Professional
 * Edition License.
 *
 * See https://visp.inria.fr for more information.
 *
 * This software was developed at:
 * Inria Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 *
 * If you have questions regarding the use of this file, please contact
 * Inria at visp@inria.fr
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Description:
 * Exceptions that can be emitted by the vpCalibration class and its derivatives.
 *
 * Authors:
 * Anthony Saunier
 *
*****************************************************************************/

#ifndef _vpCalibrationException_h_
#define _vpCalibrationException_h_

/* -------------------------------------------------------------------------
 */
/* --- INCLUDE -------------------------------------------------------------
 */
/* -------------------------------------------------------------------------
 */

/* Classes standards. */
//
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpException.h>

#include <iostream> /* Classe std::ostream.    */
#include <string>   /* Classe string.     */

/* -------------------------------------------------------------------------
 */
/* --- CLASS ---------------------------------------------------------------
 */
/* -------------------------------------------------------------------------
 */

/*!

  \class vpCalibrationException
  \brief Error that can be emitted by the vpCalibration class.
 */
class VISP_EXPORT vpCalibrationException : public vpException
{
public:
  /*!
  \brief Lists the possible error than can be emitted while calling
  vpCalibration member
 */
  enum errorCodeEnum {
    //! error returns by a constructor
    constructionError,
    //! something is not initialized
    notInitializedError,
    //! function not implemented
    notImplementedError,
    //! index out of range
    outOfRangeError,
    //! iterative algorithm doesn't converge
    convergencyError,
    forbiddenOperatorError,
  };

public:
  vpCalibrationException(int id, const char *format, ...)
  {
    this->code = id;
    va_list args;
    va_start(args, format);
    setMessage(format, args);
    va_end(args);
  }
  vpCalibrationException(int id, const std::string &msg) : vpException(id, msg) { }
  explicit vpCalibrationException(int id) : vpException(id) { }
};

#endif
