from ctypes import *

Objdl = cdll.LoadLibrary('../saturndb.dll')# *.o or *.dll

table = "1"
key="123"
value = "345"

def TestPut():
    Objdl.Put.restype = c_int
    Objdl.Put.argtypes = [c_char_p, c_char_p, c_char_p]

    result = Objdl.Put(table.encode(), key.encode(), value.encode())

    print(result)  

def TestGet():
    Objdl.Get.restype = c_char_p
    Objdl.Get.argtypes = [c_char_p, c_char_p]
    result = Objdl.Get(table.encode(), key.encode())
    decoded_result = result.decode()
    print(decoded_result)   

def TestDel():
    Objdl.Del.restype = c_int
    Objdl.Del.argtypes = [c_char_p, c_char_p]
    result = Objdl.Del(table.encode(), key.encode())
    print(result)
def TestTableDel():
    Objdl.TableDel.restype = c_int
    Objdl.TableDel.argtypes = [c_char_p]
    result = Objdl.TableDel(table.encode())
    print(result)

#TestTableDel()
#TestGet()
#TestDel()
#TestPut()