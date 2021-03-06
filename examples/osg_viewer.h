/**
 This file is part of mesh-deform.
 
 Copyright(C) 2016 Christoph Heindl
 All rights reserved.
 
 This software may be modified and distributed under the terms
 of the BSD license.See the LICENSE file for details.
 */

#ifndef DEFORM_OSG_VIEWER_H
#define DEFORM_OSG_VIEWER_H

#include <deform/openmesh_adapter.h>
#include <memory>
#include <functional>

namespace deform {
    namespace example {
    
        class OSGViewer {
        public:
            typedef OpenMesh::TriMesh_ArrayKernelT<> Mesh;
            
            typedef std::function<bool(Mesh&, double)> DeformCallback;
            
            OSGViewer(Mesh &mesh);
            OSGViewer(Mesh &mesh, const std::vector<int> &anchors, const std::vector<int> &handles);
            OSGViewer(const OSGViewer &other) = delete;
            OSGViewer &operator=(const OSGViewer &other) = delete;
            ~OSGViewer();
            
            void onFrame(DeformCallback dc);
            
            void run();
            
        private:
            
            void setupScene(const std::vector<int> &anchors, const std::vector<int> &handles);
            
            struct data;
            std::unique_ptr<data> _data;
        };
    }
}

#endif