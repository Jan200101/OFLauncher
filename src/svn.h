#ifndef SVN_H
#define SVN_H

#ifdef __cplusplus
extern "C" {
#endif
	
#ifdef _WIN32
#define SVN "svn.exe"
#else
#define SVN "/usr/bin/svn"
#endif
#define SVN_CHECKOUT "checkout"
#define SVN_UPDATE "update"

int svn_check();
int svn_checkout(char*, char*);
int svn_update(char*);
int svn_delete(char*);

#ifdef __cplusplus
}
#endif

#endif