find_package(SVNclient REQUIRED)
find_package(SVNfs REQUIRED)
find_package(SVNsubr REQUIRED)

set(SVN_LIBRARIES
    ${SVNCLIENT_LIBRARIES}
    ${SVNFS_LIBRARIES}
    ${SVNSUBR_LIBRARIES}
    )

if (MXE)
    find_package(SVNwc REQUIRED)
    find_package(SVNra REQUIRED)
    find_package(SVNrasvn REQUIRED)
    find_package(SVNralocal REQUIRED)
    find_package(SVNrepos REQUIRED)
    find_package(SVNfsfs REQUIRED)
    find_package(SVNfsx REQUIRED)
    find_package(SVNfsutil REQUIRED)
    find_package(SVNdelta REQUIRED)
    find_package(SVNdiff REQUIRED)

    # for MXE these specific libraries
    # in this specific order are needed
    set(SVN_LIBRARIES
        ${SVNCLIENT_LIBRARIES}
        ${SVNWC_LIBRARIES}
        ${SVNRA_LIBRARIES}
        ${SVNRASVN_LIBRARIES}
        ${SVNRALOCAL_LIBRARIES}
        ${SVNREPOS_LIBRARIES}
        ${SVNFS_LIBRARIES}
        ${SVNFSX_LIBRARIES}
        ${SVNFSFS_LIBRARIES}
        ${SVNDIFF_LIBRARIES}
        ${SVNSUBR_LIBRARIES}
        ${SVNFSUTIL_LIBRARIES}
        ${SVNDELTA_LIBRARIES}
        )
endif()

set(SVN_INCLUDES
    ${SVN_INCLUDE_DIRS}
    ${SVNCLIENT_INCLUDE_DIRS}
    ${SVNWC_INCLUDE_DIRS}
    ${SVNRA_INCLUDE_DIRS}
    ${SVNRASVN_INCLUDE_DIRS}
    ${SVNRALOCAL_INCLUDE_DIRS}
    ${SVNREPOS_INCLUDE_DIRS}
    ${SVNFS_INCLUDE_DIRS}
    ${SVNFSX_INCLUDE_DIRS}
    ${SVNFSFS_INCLUDE_DIRS}
    ${SVNDIFF_INCLUDE_DIRS}
    ${SVNSUBR_INCLUDE_DIRS}
    ${SVNFSUTIL_INCLUDE_DIRS}
    ${SVNDELTA_INCLUDE_DIRS}
    )