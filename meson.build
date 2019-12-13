project('min-e-calc', 'c')

compiler = meson.get_compiler('c')
incdirs = ['/usr/include/efl-1',
    '/usr/include/efl-1/interfaces',
    '/usr/include/ecore-1',
    '/usr/include/eina-1',
    '/usr/include/eina-1/eina',
    '/usr/include/eo-1',
    '/usr/include/elementary-1',
    '/usr/include/eet-1',
    '/usr/include/emile-1',
    '/usr/include/evas-1',
    '/usr/include/ecore-evas-1',
    '/usr/include/ecore-file-1',
    '/usr/include/ecore-input-1',
    '/usr/include/ecore-imf-1',
    '/usr/include/ecore-con-1',
    '/usr/include/edje-1',
    '/usr/include/eldbus-1',
    '/usr/include/efreet-1',
    '/usr/include/ethumb-client-1',
    '/usr/include/ethumb-1',
    '/usr/include/eio-1',
    '/usr/include/elocation-1']

libdirs = ['/usr/lib'] #['/home/main/Source/efl-git/pkg/efl-git/usr/lib']
libs = ['ecore', 'eina', 'efl', 'elementary', 'eo', 'ecore_con', 'ecore_wl2', 'efl_wl']
sources = ['main.c']

deps = []
foreach libname : libs
    deps += [compiler.find_library(libname, dirs : libdirs)]
endforeach

add_global_arguments('-g3', '-ggdb3', '-Og', language: 'c++')
executable('min-e-calc', sources, 
  include_directories : include_directories(incdirs),
  link_args : '-g',
  dependencies : deps,
  gui_app : true
)

