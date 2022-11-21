#include "pkg/add.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

result::Result pkg_add(Pkg pkg) {
result::Await("adding pkg config.");

  if (path::pkg_exists("custom", pkg.name))
    result::Err(ERR_CONFIG_EXISTS, state.opts.force ? C_IGNORE : C_FAIL);

  std::string s = "";
  s += s + "adding " + ANSI_COLOR_MAGENTA + pkg.name + ANSI_COLOR_RESET + " ...";
  result::printf({ s });
  save_pkg(pkg);

  return result::Ok();
}
