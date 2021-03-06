/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/


#if defined(_MSC_VER) && (_MSC_VER > 1310)
#pragma warning(disable : 4917 4555)
#endif

#include "common.h"
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/container/XNameAccess.hpp>

::rtl::OUString getStorageTypeFromGUID_Impl( GUID* guid )
{
    if ( *guid == OID_WriterTextServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "soffice.StarWriterDocument.6" ) );

    if ( *guid == OID_WriterOASISTextServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "opendocument.WriterDocument.1" ) );

    if ( *guid == OID_CalcServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "soffice.StarCalcDocument.6" ) );

    if ( *guid == OID_CalcOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "opendocument.CalcDocument.1" ) );

    if ( *guid == OID_DrawingServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "soffice.StarDrawDocument.6" ) );

    if ( *guid == OID_DrawingOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "opendocument.DrawDocument.1" ) );

    if ( *guid == OID_PresentationServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "soffice.StarImpressDocument.6" ) );

    if ( *guid == OID_PresentationOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "opendocument.ImpressDocument.1" ) );

    if ( *guid == OID_MathServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "soffice.StarMathDocument.6" ) );

    if ( *guid == OID_MathOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "opendocument.MathDocument.1" ) );

    return ::rtl::OUString();
}

::rtl::OUString getServiceNameFromGUID_Impl( GUID* guid )
{
    if ( *guid == OID_WriterTextServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Writer.TextDocument" ) );

    if ( *guid == OID_WriterOASISTextServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Writer.TextDocument" ) );

    if ( *guid == OID_CalcServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Calc.SpreadsheetDocument" ) );

    if ( *guid == OID_CalcOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Calc.SpreadsheetDocument" ) );

    if ( *guid == OID_DrawingServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Draw.DrawingDocument" ) );

    if ( *guid == OID_DrawingOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Draw.DrawingDocument" ) );

    if ( *guid == OID_PresentationServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Draw.PresentationDocument" ) );

    if ( *guid == OID_PresentationOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Draw.PresentationDocument" ) );

    if ( *guid == OID_MathServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Math.FormulaDocument" ) );

    if ( *guid == OID_MathOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.comp.Math.FormulaDocument" ) );

    return ::rtl::OUString();
}

::rtl::OUString getFilterNameFromGUID_Impl( GUID* guid )
{
    if ( *guid == OID_WriterTextServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "StarOffice XML (Writer)" ) );

    if ( *guid == OID_WriterOASISTextServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "writer8" ) );

    if ( *guid == OID_CalcServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "StarOffice XML (Calc)" ) );

    if ( *guid == OID_CalcOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "calc8" ) );

    if ( *guid == OID_DrawingServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "StarOffice XML (Draw)" ) );

    if ( *guid == OID_DrawingOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "draw8" ) );

    if ( *guid == OID_PresentationServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "StarOffice XML (Impress)" ) );

    if ( *guid == OID_PresentationOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "impress8" ) );

    if ( *guid == OID_MathServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "StarOffice XML (Math)" ) );

    if ( *guid == OID_MathOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "math8" ) );

    return ::rtl::OUString();
}

::rtl::OUString getTestFileURLFromGUID_Impl( GUID* guid )
{
    if ( *guid == OID_WriterTextServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.sxw" ) );

    if ( *guid == OID_WriterOASISTextServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.odt" ) );

    if ( *guid == OID_CalcServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.sxc" ) );

    if ( *guid == OID_CalcOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.ods" ) );

    if ( *guid == OID_DrawingServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.sxd" ) );

    if ( *guid == OID_DrawingOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.odg" ) );

    if ( *guid == OID_PresentationServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.sxi" ) );

    if ( *guid == OID_PresentationOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.odp" ) );

    if ( *guid == OID_MathServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.sxm" ) );

    if ( *guid == OID_MathOASISServer )
        return ::rtl::OUString( RTL_CONSTASCII_USTRINGPARAM ( "file:///d:/OLE_TEST/test.odf" ) );

    return ::rtl::OUString();
}

/*
::rtl::OUString getCurTypeNameFromGUID_Impl( const uno::Reference< lang::XMultiServiceFactory > xFactory, GUID* guid )
{
    ::rtl::OUString aResult;

    const ::rtl::OUString aServiceName ( RTL_CONSTASCII_USTRINGPARAM ( "com.sun.star.document.FilterFactory" ) );
    uno::Reference < container::XNameAccess > xFilters = uno::Reference < io::XOutputStream > (
    xFactory->createInstance ( aServiceName ),
    uno::UNO_QUERY );

    if ( xFilters.is() )
    {
        ::rtl::OUString aFilterName = getFilterNameFromGUID_Impl( guid );
        if ( aFilterName.getLength() )
        {
            uno::Any aAnyProp = xFilters->getByName( aFilterName );
            uno::Sequence< beans::PropertyValue > aProperties;
            if ( aAnyProp >>= aProperties ) )
            {
                for ( sal_Int32 nInd = 0; nInd < aProperties.getLength; nInd++ )
                if ( aProperties[nInd].Name.equalsAscii( "UIName" )
                {
                    aProperties[nInd].Value >>= aResult;
                    break;
                }
            }
	}
    }

    return aResult;
}
*/

// Fix strange warnings about some 
// ATL::CAxHostWindow::QueryInterface|AddRef|Releae functions.
// warning C4505: 'xxx' : unreferenced local function has been removed
#if defined(_MSC_VER)
#pragma warning(disable: 4505)
#endif
