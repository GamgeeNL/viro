//
//  VROSurface.h
//  ViroRenderer
//
//  Created by Raj Advani on 12/3/15.
//  Copyright © 2015 Viro Media. All rights reserved.
//

#ifndef VROSurface_h
#define VROSurface_h

#include "VROGeometry.h"
#include "VROShapeUtils.h"
#include <memory>

class VROSurface : public VROGeometry {
    
public:
    
    static std::shared_ptr<VROSurface> createSurface(float width, float height,
                                                     float u0 = 0, float v0 = 0, float u1 = 1, float v1 = 1);
    static std::shared_ptr<VROSurface> createSurface(float x, float y, float width, float height,
                                                     float u0, float v0, float u1, float v1);
    virtual ~VROSurface();
    
    /*
     Set physical dimensions of the surface.
     */
    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);
    
    /*
     Set texture coordinates of the surface, and an optional transform.
     */
    void setU0(float u0);
    void setU1(float u1);
    void setV0(float v0);
    void setV1(float v1);
    void setTexcoordTransform(VROMatrix4f transform);
    
    /*
     Directly set the texture coordinates of all four corners.
     */
    void setTextureCoordinates(VROVector3f BL, VROVector3f BR, VROVector3f TL, VROVector3f TR);
    
    float getU0() const { return _u0; }
    float getU1() const { return _u1; }
    float getV0() const { return _v0; }
    float getV1() const { return _v1; }
    
    float getX() const { return _x; }
    float getY() const { return _y; }
    float getWidth() const { return _width; }
    float getHeight() const { return _height; }
    
protected:
    
    VROSurface(float x, float y, float width, float height,
               float u0, float v0, float u1, float v1);
    
private:
    
    void updateSurface();

    void buildGeometry(float x, float y, float width, float height,
                       VROVector3f texBL, VROVector3f texBR, VROVector3f texTL, VROVector3f texTR,
                       std::vector<std::shared_ptr<VROGeometrySource>> &sources,
                       std::vector<std::shared_ptr<VROGeometryElement>> &elements);
    void buildSurface(VROShapeVertexLayout *vertexLayout,
                      float left, float bottom, float right, float top,
                      VROVector3f texBL, VROVector3f texBR, VROVector3f texTL, VROVector3f texTR);
    
    float _x, _y, _width, _height;
    float _u0, _v0, _u1, _v1;
    
    /*
     Transform by which to multiply all texture coordinates.
     */
    VROMatrix4f _texcoordTransform;
    
};

#endif /* VROSurface_h */
