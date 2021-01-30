#ifndef SVN_H
#define SVN_H

#ifdef __cplusplus
extern "C" {
#endif

int svn_init();
int svn_checkout(char*, char*);
int svn_update(char*);
int svn_delete(char*);

#ifdef __cplusplus
}
#endif

#endif