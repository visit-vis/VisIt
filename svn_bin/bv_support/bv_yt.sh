function bv_yt_initialize
{
    export DO_YT="no"
    export ON_YT="off"

    #[ -z "$HDF5_DIR" ] && get_ytproject hdf5-1.8.7.tar.gz
    INST_HG=1       # Install Mercurial or not?  If hg is not already
                    # installed, yt cannot be installed.
    INST_ZLIB=1     # On some systems (Kraken) matplotlib has issues with 
                    # the system zlib, which is compiled statically.
                    # If need be, you can turn this off.
    INST_BZLIB=1    # On some systems, libbzip2 is missing.  This can
                    # lead to broken mercurial installations.
    INST_PNG=1      # Install a local libpng?  Same things apply as with zlib.
    INST_FTYPE=1    # Install FreeType2 locally?
    INST_ENZO=0     # Clone a copy of Enzo?
    INST_SQLITE3=1  # Install a local version of SQLite3?
    INST_PYX=0      # Install PyX?  Sometimes PyX can be problematic without a
                    # working TeX installation.
    INST_0MQ=1      # Install 0mq (for IPython) and affiliated bindings?

    if type -P wget &>/dev/null
    then
        echo "Using wget for yt"
        export GETFILE="wget -nv"
    else
        echo "Using curl for yt"
        export GETFILE="curl -sSO"
    fi

#export USE_SYSTEM_YT="no"
#add_extra_commandline_args "yt" "alt-yt-dir" 1 "Use alternative directory for Yt" 
}

function bv_yt_enable
{
DO_YT="yes"
ON_YT="on"
}

function bv_yt_disable
{
DO_YT="no"
ON_YT="off"
}

#function bv_yt_alt_yt_dir
#{
#    bv_yt_enable
#    USE_SYSTEM_YT="yes"
#    YT_INSTALL_DIR="$1"
#}

function bv_yt_depends_on
{
echo "szip hdf5"
}

function bv_yt_info
{
export YT_FILE=${YT_FILE:-"yt"}
export YT_VERSION=${YT_VERSION:-"2.4"}
export YT_COMPATIBILITY_VERSION=${YT_COMPATIBILITY_VERSION:-"2.4"}
export YT_BUILD_DIR=${YT_BUILD_DIR:-"yt"}
export YT_MD5_CHECKSUM=""
export YT_SHA256_CHECKSUM=""
}

function bv_yt_initialize_vars
{
export YT_INSTALL_DIR="${VISITDIR}/yt/$YT_VERSION/${VISITARCH}"
}

function bv_yt_print
{
  printf "%s%s\n" "YT_FILE=" "${YT_FILE}"
  printf "%s%s\n" "YT_VERSION=" "${YT_VERSION}"
  printf "%s%s\n" "YT_COMPATIBILITY_VERSION=" "${YT_COMPATIBILITY_VERSION}"
  printf "%s%s\n" "YT_BUILD_DIR=" "${YT_BUILD_DIR}"
}

function bv_yt_print_usage
{
printf "%-15s %s [%s]\n" "--yt"   "Install Yt" "$DO_YT"
}

function bv_yt_graphical
{
local graphical_out="Yt    $YT_VERSION($YT_FILE)    $ON_YT"
echo $graphical_out
}

function bv_yt_host_profile
{
    if [[ "$DO_YT" == "yes" ]] ; then
        echo >> $HOSTCONF
        echo "##" >> $HOSTCONF
        echo "## YT" >> $HOSTCONF
        echo "##" >> $HOSTCONF
        echo "VISIT_OPTION_DEFAULT(VISIT_YT_DIR $YT_INSTALL_DIR)" >> $HOSTCONF
    fi
}

function bv_yt_ensure
{
    #if [[ "$DO_YT" == "yes" ]] ; then
    #    ensure_built_or_ready "yt" $YT_VERSION $YT_BUILD_DIR $YT_FILE
    #    if [[ $? != 0 ]] ; then
    #        ANY_ERRORS="yes"
    #        DO_YT="no"
    #        error "Unable to build Yt.  ${YT_FILE} not found."
    #    fi
    #fi
    info "nothing to ensure for Yt"
}

function bv_yt_dry_run
{
  if [[ "$DO_YT" == "yes" ]] ; then
    echo "Dry run option not set for Yt."
  fi
}

# ***************************************************************************
#                         Function 8.22, build_YT
#
# Modifications:
#
# ***************************************************************************
function do_exit
{
    info "Yt installation failed"
    exit 0
}
function do_setup_py
{
    [ -e $1/done ] && return
    info "Installing $1 (arguments: '$*')"
    [ ! -e $1/extracted ] && tar xfz $1.tar.gz
    touch $1/extracted
    cd $1
    if [ ! -z `echo $1 | grep h5py` ]
    then
        shift
    ( ${PYTHON_COMMAND} setup.py build --hdf5=${HDF5_DIR} $* 2>&1 ) 1>> ${LOG_FILE} || do_exit
    else
        shift
        ( ${PYTHON_COMMAND} setup.py build   $* 2>&1 ) 1>> ${LOG_FILE} || do_exit
    fi
    ( ${PYTHON_COMMAND} setup.py install    2>&1 ) 1>> ${LOG_FILE} || do_exit
    touch done
    cd ..
}


function get_ytproject
{
    echo "Downloading $1 from yt-project.org"
    [ -e $1 ] && return
    ${GETFILE} "http://yt-project.org/dependencies/$1" || do_exit
    #( ${SHASUM} -c $1.sha512 2>&1 ) 1>> ${LOG_FILE} || do_exit
}

function build_yt_bzlib
{
if [ $INST_BZLIB -eq 1 ]
then
    if [ ! -e bzip2-1.0.5/done ]
    then
        [ ! -e bzip2-1.0.5 ] && tar xfz bzip2-1.0.5.tar.gz
        info "Installing BZLIB"
        cd bzip2-1.0.5
        if [ `uname` = "Darwin" ]
        then
            if [ -z "${CC}" ]
            then
                sed -i.bak 's/soname/install_name/' Makefile-libbz2_so
            else
                sed -i.bak -e 's/soname/install_name/' -e "s/CC=gcc/CC=${CC}/" Makefile-libbz2_so
            fi
        fi
        ( make install CFLAGS=-fPIC LDFLAGS=-fPIC PREFIX=${DEST_DIR} 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make -f Makefile-libbz2_so CFLAGS=-fPIC LDFLAGS=-fPIC PREFIX=${DEST_DIR} 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( cp -v libbz2.so.1.0.4 ${DEST_DIR}/lib 2>&1 ) 1>> ${LOG_FILE} || do_exit
        touch done
        cd ..
    fi
    BZLIB_DIR=${DEST_DIR}
    export LDFLAGS="${LDFLAGS} -L${BZLIB_DIR}/lib/ -L${BZLIB_DIR}/lib64/"
    LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${BZLIB_DIR}/lib/"
fi
}

function build_yt_zlib
{
if [ $INST_ZLIB -eq 1 ]
then
    if [ ! -e zlib-1.2.3/done ]
    then
        [ ! -e zlib-1.2.3 ] && tar xfj zlib-1.2.3.tar.bz2
        info "Installing ZLIB"
        cd zlib-1.2.3
        ( ./configure --shared --prefix=${DEST_DIR}/ 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make install 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make clean 2>&1) 1>> ${LOG_FILE} || do_exit
        touch done
        cd ..
    fi
    ZLIB_DIR=${DEST_DIR}
    export LDFLAGS="${LDFLAGS} -L${ZLIB_DIR}/lib/ -L${ZLIB_DIR}/lib64/"
    LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${ZLIB_DIR}/lib/"
fi
}

function build_yt_png
{
if [ $INST_PNG -eq 1 ]
then
    if [ ! -e libpng-1.5.12/done ]
    then
        [ ! -e libpng-1.5.12 ] && tar xfz libpng-1.5.12.tar.gz
        info "Installing PNG"
        cd libpng-1.5.12
        ( ./configure CPPFLAGS=-I${DEST_DIR}/include CFLAGS=-I${DEST_DIR}/include --prefix=${DEST_DIR}/ 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make install 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make clean 2>&1) 1>> ${LOG_FILE} || do_exit
        touch done
        cd ..
    fi
    PNG_DIR=${DEST_DIR}
    export LDFLAGS="${LDFLAGS} -L${PNG_DIR}/lib/ -L${PNG_DIR}/lib64/"
    LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${PNG_DIR}/lib/"
fi
}

function build_yt_ftype
{
if [ $INST_FTYPE -eq 1 ]
then
    if [ ! -e freetype-2.4.4/done ]
    then
        [ ! -e freetype-2.4.4 ] && tar xfz freetype-2.4.4.tar.gz
        info "Installing FreeType2"
        cd freetype-2.4.4
        ( ./configure CFLAGS=-I${DEST_DIR}/include --prefix=${DEST_DIR}/ 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make install 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make clean 2>&1) 1>> ${LOG_FILE} || do_exit
        touch done
        cd ..
    fi
    FTYPE_DIR=${DEST_DIR}
    export LDFLAGS="${LDFLAGS} -L${FTYPE_DIR}/lib/ -L${FTYPE_DIR}/lib64/"
    LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${FTYPE_DIR}/lib/"
fi
}

function build_yt_hdf5
{
if [ -z "$HDF5_DIR" ]
then
    if [ ! -e hdf5-1.8.7/done ]
    then
        [ ! -e hdf5-1.8.7 ] && tar xfz hdf5-1.8.7.tar.gz
        info "Installing HDF5"
        cd hdf5-1.8.7
        ( ./configure --prefix=${DEST_DIR}/ --enable-shared 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make ${MAKE_PROCS} install 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make clean 2>&1) 1>> ${LOG_FILE} || do_exit
        touch done
        cd ..
    fi
    export HDF5_DIR=${DEST_DIR}
else
    export HDF5_DIR=${HDF5_DIR}
fi
export HDF5_API=16
}

function build_yt_sqlite
{
if [ $INST_SQLITE3 -eq 1 ]
then
    if [ ! -e sqlite-autoconf-3070500/done ]
    then
        [ ! -e sqlite-autoconf-3070500 ] && tar xfz sqlite-autoconf-3070500.tar.gz
        info "Installing SQLite3"
        cd sqlite-autoconf-3070500
        ( ./configure --prefix=${DEST_DIR}/ 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make ${MAKE_PROCS} install 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make clean 2>&1) 1>> ${LOG_FILE} || do_exit
        touch done
        cd ..
    fi
fi
}

function build_yt_hg
{
if [ $INST_HG -eq 1 ]
then
    info "Installing Mercurial."
    do_setup_py mercurial-2.2.2
    export HG_EXEC=${VISIT_PYTHON_DIR}/bin/hg
else
    # We assume that hg can be found in the path.
    if type -P hg &>/dev/null
    then
        export HG_EXEC=hg
    else
        info "Cannot find mercurial.  Please set INST_HG=1."
        do_exit
    fi
fi
}

function build_yt_zmq
{
if [ $INST_0MQ -eq 1 ]
then
    if [ ! -e zeromq-2.2.0/done ]
    then
        [ ! -e zeromq-2.2.0 ] && tar xfz zeromq-2.2.0.tar.gz
        info "Installing ZeroMQ"
        cd zeromq-2.2.0
        ( ./configure --prefix=${DEST_DIR}/ 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make install 2>&1 ) 1>> ${LOG_FILE} || do_exit
        ( make clean 2>&1) 1>> ${LOG_FILE} || do_exit
        touch done
        cd ..
    fi
    do_setup_py pyzmq-2.1.11 --zmq=${DEST_DIR}
    do_setup_py tornado-2.2
fi
}

function build_yt
{
    info "Making Yt ..."

    BACKUP_CFLAGS="${CFLAGS}"
    BACKUP_CXXFLAGS="${CXXFLAGS}"
    BACKUP_LDFLAGS="${LDFLAGS}"
    BACKUP_LD_LIBRARY_PATH="${LD_LIBRARY_PATH}"
    DEST_DIR="$YT_INSTALL_DIR"

    mkdir -p "$YT_BUILD_DIR"
    cd "$YT_BUILD_DIR"

    # If you've got YT some other place, set this to point to it.
    YT_DIR=""
    YT_BRANCH="stable"

    # If you need to pass anything to matplotlib, do so here.
    MPL_SUPP_LDFLAGS=""
    MPL_SUPP_CFLAGS=""
    MPL_SUPP_CXXFLAGS=""

    # If you want to spawn multiple Make jobs, here's the place to set the
    # arguments.  For instance, "-j4"
    MAKE_PROCS="$MAKE_OPT_FLAGS"

    #[ -z "$HDF5_DIR" ] && get_ytproject hdf5-1.8.7.tar.gz
    [ $INST_ZLIB -eq 1 ] && get_ytproject zlib-1.2.3.tar.bz2
    [ $INST_BZLIB -eq 1 ] && get_ytproject bzip2-1.0.5.tar.gz
    [ $INST_PNG -eq 1 ] && get_ytproject libpng-1.5.12.tar.gz
    [ $INST_FTYPE -eq 1 ] && get_ytproject freetype-2.4.4.tar.gz
    [ $INST_SQLITE3 -eq 1 ] && get_ytproject sqlite-autoconf-3070500.tar.gz
    [ $INST_PYX -eq 1 ] && get_ytproject PyX-0.11.1.tar.gz
    [ $INST_0MQ -eq 1 ] && get_ytproject zeromq-2.2.0.tar.gz
    [ $INST_0MQ -eq 1 ] && get_ytproject pyzmq-2.1.11.tar.gz
    [ $INST_0MQ -eq 1 ] && get_ytproject tornado-2.2.tar.gz

    get_ytproject Python-2.7.2.tgz
    get_ytproject numpy-1.6.1.tar.gz
    get_ytproject matplotlib-1.1.0.tar.gz
    get_ytproject mercurial-2.2.2.tar.gz
    get_ytproject ipython-0.13.tar.gz
    get_ytproject h5py-2.0.1.tar.gz
    get_ytproject Cython-0.16.tar.gz
    get_ytproject reason-js-20120623.zip

    #install helper libraries
    build_yt_bzlib
    build_yt_zlib
    build_yt_png
    build_yt_ftype

    info "Enabling HDF5"
    HDF5_DIR="$HDF5_INSTALL_DIR"

    build_yt_sqlite

    PYTHONPATH="${VISIT_PYTHON_DIR}/lib/python${PYTHON_COMPATIBILITY_VERSION}/site-packages/"
    info "Setting PYTHONPATH=${PYTHONPATH}"
    
    build_yt_hg

    info "Building Yt . . ."
    if [ -z "$YT_DIR" ]
then
    if [ -e $ORIG_PWD/yt/mods.py ]
    then
        YT_DIR="$ORIG_PWD"
    elif [ -e $ORIG_PWD/../yt/mods.py ]
    then
        YT_DIR=`dirname $ORIG_PWD`
    elif [ ! -e yt-hg ]
    then
        YT_DIR="$PWD/yt-hg/"
        ( ${HG_EXEC} --debug clone https://bitbucket.org/yt_analysis/yt-supplemental/ 2>&1 ) 1>> ${LOG_FILE}
        # Recently the hg server has had some issues with timeouts.  In lieu of
        # a new webserver, we are now moving to a three-stage process.
        # First we clone the repo, but only up to r0.
        ( ${HG_EXEC} --debug clone https://bitbucket.org/yt_analysis/yt/ ./yt-hg 2>&1 ) 1>> ${LOG_FILE}
        # Now we update to the branch we're interested in.
        ( ${HG_EXEC} -R ${YT_DIR} up -C ${YT_BRANCH} 2>&1 ) 1>> ${LOG_FILE}
    elif [ -e yt-hg ]
    then
        YT_DIR="$PWD/yt-hg/"
    fi
    echo Setting YT_DIR=${YT_DIR}
fi

    #restore changes..
    #LDFLAGS="${BACKUP_LDFLAGS}"
    CFLAGS="$CFLAGS -I${DEST_DIR}/include"
    CXXFLAGS="$CXXFLAGS -I${DEST_DIR}/include"

    info "Installing distribute "
    ( ${PYTHON_COMMAND} ${YT_DIR}/distribute_setup.py 2>&1 ) 1>> ${LOG_FILE} || do_exit
  
    info "Installing pip"
( ${VISIT_PYTHON_DIR}/bin/easy_install pip 2>&1 ) 1>> ${LOG_FILE} || do_exit

    do_setup_py numpy-1.6.1 ${NUMPY_ARGS}

    mkdir -p matplotlib-1.1.0
    echo "[directories]" >> matplotlib-1.1.0/setup.cfg
    echo "basedirlist = ${DEST_DIR}" >> matplotlib-1.1.0/setup.cfg
    do_setup_py matplotlib-1.1.0

    build_yt_zmq

    info "Installing IPython"
    do_setup_py ipython-0.13
    info "Installing H5py"
    do_setup_py h5py-2.0.1
    info "Installing Cython"
    do_setup_py Cython-0.16

    info "Doing Yt update, wiping local changes and updating to branch ${YT_BRANCH}"
    MY_PWD=`pwd`
    cd "$YT_DIR"
    ( ${HG_EXEC} pull 2>1 && ${HG_EXEC} up -C 2>1 ${YT_BRANCH} 2>&1 ) 1>> ${LOG_FILE}

    info "Installing Yt ..."
    echo "$HDF5_DIR" > hdf5.cfg
    [ $INST_PNG -eq 1 ] && echo "$PNG_DIR" > png.cfg
    [ $INST_FTYPE -eq 1 ] && echo "$FTYPE_DIR" > freetype.cfg
    ( ${PYTHON_COMMAND} setup.py develop 2>&1 ) 1>> ${LOG_FILE} || do_exit
    touch done
    cd "$MY_PWD"

    CFLAGS="${BACKUP_CFLAGS}"
    CXXFLAGS="${BACKUP_CXXFLAGS}"
    LDFLAGS="${BACKUP_LDFLAGS}"
    LD_LIBRARY_PATH="${BACKUP_LD_LIBRARY_PATH}"
    #go back to START_DIR..
    cd "$START_DIR"
    info "Done with Yt"
}

function bv_yt_is_enabled
{
    if [[ $DO_YT == "yes" ]]; then
        return 1    
    fi
    return 0
}

function bv_yt_is_installed
{
    check_if_installed "yt" $YT_VERSION
    if [[ $? == 0 ]] ; then
        return 1
    fi
    return 0
}

function bv_yt_build
{
cd "$START_DIR"
if [[ "$DO_YT" == "yes" ]] ; then
    check_if_installed "yt" $YT_VERSION
    if [[ $? == 0 ]] ; then
        info "Skipping Yt build.  Yt is already installed."
    else
        info "Building Yt (~20 minutes)"
        build_yt
        if [[ $? != 0 ]] ; then
            error "Unable to build or install Yt.  Bailing out."
        fi
        info "Done building Yt"
   fi
fi
}

