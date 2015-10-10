import os
import re
import shutil
res_dir = "all"

r_pname=re.compile("[0-9]*.cbp")
r_cppfile=re.compile("[0-9]*.cpp")
def walk (path,target_dir): 
	pname="nope"
	cppfile="nope"
	for name in os.listdir(path):
		if os.path.isfile(os.path.join(path,name)):
			if r_pname.search(name):
				pname = name.split('.');
				pname = pname[0];
			if (r_cppfile.search(name)) and (cppfile!="main.cpp"):
				cppfile = name;
		else:
			walk(os.path.join(path,name),target_dir)
	if (pname!="nope") and (cppfile!="nope"):
		shutil.copyfile(os.path.join(path,cppfile), os.path.join(target_dir,pname+".cpp"))
	
walk(os.getcwd(),os.path.join(os.getcwd(),res_dir))
