#include<SDL2/SDL.h>
#include"mylisp/value.hh"

inline Value load1();

extern "c" {
  Value load() {
    return load1();
  }
}

inline Value load1() {}
