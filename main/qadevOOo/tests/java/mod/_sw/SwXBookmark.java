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



package mod._sw;

import java.io.PrintWriter;

import lib.StatusException;
import lib.TestCase;
import lib.TestEnvironment;
import lib.TestParameters;
import util.SOfficeFactory;

import com.sun.star.lang.XMultiServiceFactory;
import com.sun.star.text.XTextContent;
import com.sun.star.text.XTextDocument;
import com.sun.star.uno.UnoRuntime;
import com.sun.star.uno.XInterface;

/**
 * Test for object which is represented by service
 * <code>com.sun.star.text.Bookmark</code>. <p>
 * Object implements the following interfaces :
 * <ul>
 *  <li> <code>com::sun::star::container::XNamed</code></li>
 *  <li> <code>com::sun::star::lang::XComponent</code></li>
 *  <li> <code>com::sun::star::text::XTextContent</code></li>
 *  <li> <code>com::sun::star::text::TextContent</code></li>
 * </ul> <p>
 * This object test <b> is NOT </b> designed to be run in several
 * threads concurently.
 * @see com.sun.star.container.XNamed
 * @see com.sun.star.lang.XComponent
 * @see com.sun.star.text.XTextContent
 * @see com.sun.star.text.TextContent
 * @see ifc.container._XNamed
 * @see ifc.lang._XComponent
 * @see ifc.text._XTextContent
 * @see ifc.text._TextContent
 */
public class SwXBookmark extends TestCase {
    XTextDocument xTextDoc;
    SOfficeFactory SOF;

    /**
    * Creates text document.
    */
    protected void initialize( TestParameters tParam, PrintWriter log ) {
        SOfficeFactory SOF = SOfficeFactory.getFactory( (XMultiServiceFactory)tParam.getMSF() );
        try {
            log.println( "creating a textdocument" );
            xTextDoc = SOF.createTextDoc( null );
        } catch ( com.sun.star.uno.Exception e ) {
            e.printStackTrace( log );
            throw new StatusException( "Couldn't create document", e );
        }
    }

    /**
    * Disposes text document.
    */
    protected void cleanup( TestParameters tParam, PrintWriter log ) {
        log.println( "    disposing xTextDoc " );
        util.DesktopTools.closeDoc(xTextDoc);
    }

    /**
    * Creating a Testenvironment for the interfaces to be tested. After creating
    * a bookmark, it is inserted to the text document.
    */
    protected synchronized TestEnvironment createTestEnvironment(TestParameters tParam, PrintWriter log) {
        SOfficeFactory SOF = SOfficeFactory.getFactory( (XMultiServiceFactory)tParam.getMSF());
        XInterface oObj = null;
        Object instance = null;
        log.println( "creating a test environment" );
        try {
            oObj = SOF.createBookmark( xTextDoc );
            SOF.insertTextContent( xTextDoc, (XTextContent) oObj );
            instance = SOF.createInstance(xTextDoc,"com.sun.star.text.Bookmark");
        } catch ( com.sun.star.uno.Exception e ) {
            e.printStackTrace( log );
            throw new StatusException( "Couldn't create Bookmark", e );
        }
        log.println( "creating a new environment for bodytext object" );
        TestEnvironment tEnv = new TestEnvironment( oObj );

        util.dbg.printInterfaces((XInterface) instance);

        tEnv.addObjRelation("CONTENT", (XTextContent)
                        UnoRuntime.queryInterface(XTextContent.class,instance));
        tEnv.addObjRelation("RANGE", xTextDoc.getText().createTextCursor());
        return tEnv;
    } // finish method getTestEnvironment


}    // finish class SwXBookmark
