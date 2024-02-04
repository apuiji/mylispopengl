#include<GL/gl.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include"mylisp/iconvs.hh"
#include"mylisp/maps.hh"

using namespace std;

namespace zlt::mylisp::opengl {
  inline int exp0rt(Value &dest);
}

extern "C" {
  int mylispExport(zlt::mylisp::Value &dest) {
    return zlt::mylisp::opengl::exp0rt(dest);
  }
}

namespace zlt::mylisp::opengl {
  struct WindowObj final: Object {
    GLFWwindow *value;
    WindowObj(GLFWwindow *value) noexcept: value(value) {}
  };

  static NativeFunction openWindow;

  inline int exp0rt(Value &dest) {
    MapObj::StrPool sp;
    sp[constring<'o', 'p', 'e', 'n', 'W', 'i', 'n', 'd', 'o', 'w'>] = openWindow;
    MapObj *mod = neobj<MapObj>();
    mod->strPool = std::move(sp);
    dest = mod;
    return 0;
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
