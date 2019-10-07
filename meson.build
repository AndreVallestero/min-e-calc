project('min-e-calc', 'c')

compiler = meson.get_compiler('c')
incdirs = ['/usr/include/efl-1',
    '/usr/include/ecore-1',
    '/usr/include/eina-1',
    '/usr/include/eina-1/eina',
    '/usr/include/eo-1']

libdirs = ['/lib64','/usr/lib64']
libs = ['ecore']
sources = ['main.c']

deps = []
foreach libname : libs
    deps += [compiler.find_library(libname, dirs : libdirs)]
endforeach

executable('min-e-calc', sources, 
  include_directories : include_directories(incdirs),
  dependencies : deps,
  #link_args : ['pkg-config'],
  gui_app : true
)

