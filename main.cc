#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<GL/gl.h>
#include<glm/glm.hpp>
#include"mylisp/iconvs.hh"

using namespace std;

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
  struct WindowObj final: Object {
    GLFWwindow *value;
    WindowObj(GLFwindow *value) noexcept: value(value) {}
  };

  static NativeFunction openWindow;
  static NativeFunction closeWindow;

  inline Value exp0rt() {
    MapObj::StrPool sp;
    sp[constring<'o', 'p', 'e', 'n', 'W', 'i', 'n', 'd', 'o', 'w'>] = openWindow;
    sp[constring<'c', 'l', 'o', 's', 'e', 'W', 'i', 'n', 'd', 'o', 'w'>] = closeWindow;
    MapObj *mod = neobj<MapObj>();
    mod->strPool = std::move(sp);
    return mod;
  }

  Value openWindow(const Value *it, const Value *end) {
    int width;
    int height;
    wstring_view title;
    if (!dynamicasts(make_tuple(&width, &height, &title), it, end)) [[unlikely]] {
      return Null();
    }
    string title1;
    if (!strconv(title1, title)) {
      title1 = "";
    }
    auto window = glfwCreateWindow(width, height, title1.data(), nullptr, nullptr);
    if (!window) {
      return Null();
    }
    return neobj<WindowObj>(window);
  }
}
