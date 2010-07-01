#!/usr/bin/env/python

from distutils.core import setup, Extension
from distutils.sysconfig import get_python_inc
from distutils.util import *

plt = get_platform()

print plt

author = 'David Arcoleo'

sources = ['hello_module.c']

module1 = Extension('dsa_hello',
    sources = sources)

setup (name = 'dsa_hello',
    version = '1.0',
    description = 'This is a demo package',
    ext_modules = [module1])
