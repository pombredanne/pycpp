#include <Python.h>


static char dsa_hello_getnone_doc[] =
"Returns None";

static PyObject *
dsa_hello_getnone(PyObject *self, PyObject *args)
{
    Py_INCREF(Py_None);
    return Py_None;
}

// ---------------------------------------

static char dsa_hello_helloworld_doc[] =
"Simple string example.  Returns 'Hello World!'.";

static PyObject *
dsa_hello_helloworld(PyObject *self, PyObject *args)
{
    char str[] = "Hello World!";
    
    return Py_BuildValue("s", str);
}

// ---------------------------------------

static char dsa_hello_five_doc[] =
"Simple integer example.  Returns int value 5";

static PyObject *
dsa_hello_five(PyObject *self, PyObject *args)
{
    int val = 5;

    return Py_BuildValue("i", val);
}

// ---------------------------------------

static char dsa_hello_nameage_doc[] =
"Simple parameter parsing example.  Takes a (string, int) and return a string.";

static PyObject *
dsa_hello_nameage(PyObject *self, PyObject *args)
{
    const char *name;
    int val;
    char *buf = malloc(129);

    if (!PyArg_ParseTuple(args, "si", &name, &val))
        return NULL;

    snprintf(buf, 128, "Hello %s, you are %d years old.", name, val);
    return Py_BuildValue("s", buf);
}

// ---------------------------------------

static char dsa_hello_fs_doc[] =
"Simple parameter parsing example.  Takes a (float, string) and returns \
a (string, int).";

static PyObject *
dsa_hello_fs(PyObject *self, PyObject *args)
{
    float val;
    const char *str;

    if (!PyArg_ParseTuple(args, "fs", &val, &str))
        return NULL;

    return Py_BuildValue("fs", val, str);
}

// ---------------------------------------
static PyMethodDef dsa_hello_methods[] = {
	{"getnone", dsa_hello_getnone, METH_VARARGS, dsa_hello_getnone_doc},
        {"helloworld", dsa_hello_helloworld, METH_VARARGS, dsa_hello_helloworld_doc},
        {"five", dsa_hello_five, METH_VARARGS, dsa_hello_five_doc},
        {"nameage", dsa_hello_nameage, METH_VARARGS, dsa_hello_nameage_doc},
        {"fs", dsa_hello_fs, METH_VARARGS, dsa_hello_fs_doc},
	{NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initdsa_hello(void)
{
    PyObject *m;

    m = Py_InitModule("dsa_hello", dsa_hello_methods);
    if (m == NULL)
        return;
};
