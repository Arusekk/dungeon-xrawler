#ifndef HEADER_DUNGEON_XRAWLER_STORAGE_H
#define HEADER_DUNGEON_XRAWLER_STORAGE_H

#define MAXBOARD 200
#define xmalloc(s) xmalloc_f(s,__FILE__,__LINE__)
#define xvmalloc(v,s) v=(decltype(v))xmalloc(s)

#endif // HEADER_DUNGEON_XRAWLER_STORAGE_H
