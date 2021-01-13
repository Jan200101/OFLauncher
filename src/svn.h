#ifndef SVN_H
#define SVN_H

#define SVN "/usr/bin/svn"
#define SVN_CHECKOUT "checkout"
#define SVN_UPDATE "update"

int svn_check();
int svn_checkout(char*, char*);
int svn_update(char*);
int svn_delete(char*);

#endif