#ifndef BOXLIB_EXPORTS_H
#define BOXLIB_EXPORTS_H

#if defined(_WIN32)
#ifdef BOXLIB_EXPORTS
#define BOXLIB_API __declspec(dllexport)
#else
#define BOXLIB_API __declspec(dllimport)
#endif
#else
#define BOXLIB_API 
#endif

#endif