

import os
import sys
import pip

def pip_install(pkg_name,dest,pkg_ver=None):
    if pkg_ver != None:
        pkg_name += "==" + pkg_ver
    opts = ["install",
            pkg_name,
            "--build",
            "_pip_build",
            "--download-cache",
            "_pip_dl",
            "--target",
            dest]
    print " ".join(opts)
    pip.main(opts)
    

def main():
    dest = sys.argv[1]
    dest = os.path.abspath(dest)
    # use base_pkgs for debugging
    # base_pkgs  = ["numpy","ply"]
    # for pkg_name in base_pkgs:
    #     pip_install(pkg_name,dest=dest)
    for pkg in pip.get_installed_distributions():
        print pkg
        pkg_name = pkg.project_name
        pkg_ver  = pkg.version
        pip_install(pkg_name,pkg_ver,dest)

if __name__ == "__main__":
    main()

