#include <Python.h>

static char dsa_nothing_getnone_doc[] =
"Returns None";

static PyObject *
dsa_nothing_getnone(PyObject *self, PyObject *args)
{
    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef dsa_nothing_methods[] = {
	{"getnone", dsa_nothing_getnone, METH_VARARGS, dsa_nothing_getnone_doc},
	{NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initdsa_nothing(void)
{
    PyObject *m;

    m = Py_InitModule("dsa_nothing", dsa_nothing_methods);
    if (m == NULL)
        return;  
};
