#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

/*Trying to figure out how to handle error codes
 *
 */
enum ERROR_CODE {
  SDL_ERROR,
  VIDEO_ERROR,
  WINDOW_CREATION_ERROR,
  RENDER_FAILED
};
enum ERROR_CODE ERROR_CODE;

void SDL_INIT_Error();
void SDL_WINDOW_Error();
void exceptionHanlder(int exception);

#endif
