project(
  'toy_use_mkl',
   'c',
   version : '1.1.0',
   default_options : ['warning_level=3']
)

mkldep = dependency('mkl-dynamic-ilp64-iomp')
executable('toy_use_mkl', 'use_mkl.c', dependencies: mkldep)
