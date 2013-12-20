/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013 Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

#include "Context.h"
#include "Extensions.h"
#include "Mesh.h"
#include "Test/AbstractOpenGLTester.h"

namespace Magnum { namespace Test {

class MeshGLTest: public AbstractOpenGLTester {
    public:
        explicit MeshGLTest();

        void label();
};

MeshGLTest::MeshGLTest() {
    addTests({&MeshGLTest::label});
}

void MeshGLTest::label() {
    /* No-Op version is tested in AbstractObjectGLTest */
    if(!Context::current()->isExtensionSupported<Extensions::GL::KHR::debug>() &&
       !Context::current()->isExtensionSupported<Extensions::GL::EXT::debug_label>())
        CORRADE_SKIP("Required extension is not available");

    Mesh mesh;
    CORRADE_COMPARE(mesh.label(), "");

    mesh.setLabel("MyMesh");
    CORRADE_COMPARE(mesh.label(), "MyMesh");

    MAGNUM_VERIFY_NO_ERROR();
}

}}

CORRADE_TEST_MAIN(Magnum::Test::MeshGLTest)
