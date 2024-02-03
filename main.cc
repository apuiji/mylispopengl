#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<GL/gl.h>
#include<glm/glm.hpp>
#include"mylisp/object.hh"

namespace zlt::mylisp::opengl {
  static inline Value exp0rt() {
    ;
  }
}

extern "c" {
  Value mylispExport() {
    return zlt::mylisp::opengl::exp0rt();
  }
}

namespace zlt::mylisp::opengl {
  static NativeFunction openWindow;
  static NativeFunction closeWindow;

  inline Value exp0rt() {
    MapObj::StrPool sp;
    sp[constring<'o', 'p', 'e', 'n', 'W', 'i', 'n', 'd', 'o', 'w'>] = openWindow;
    sp[constring<'c', 'l', 'o', 's', 'e', 'W', 'i', 'n', 'd', 'o', 'w'>] = closeWindow;
    MapObj *mod = neobj<MapObj>();
    return mod;
  }

  Value openWindow(const Value *it, const Value *end) {
    double width;
    double height;
    wstring_view title;
    if (!dynamicasts(make_tuple(&width, &height, &title), it, end)) {
      return Null();
    }
  }
}
