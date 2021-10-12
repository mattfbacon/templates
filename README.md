# Project Templates

I use these templates sometimes when I create new projects so I figured they might be helpful for others.

If you use one of these templates your project is not considered a derivative work. You can give attribution but are not required.

Make sure to remove .gitkeep with something like `find -type f -name ".gitkeep" -delete` or `rm **/.gitkeep`.

Also, make sure to replace all occurrences of `FILLTHISIN` with the proper values. You can probably just do `find -type f -exec grep 'FILLTHISIN' {} \+`.

## What is `c_cpp_properties.json`?

It tells the VS Code C/C++ extension how your project refers to other code. It goes in the `.vscode` directory in the project. Since I have that folder in my global `.gitignore`, none of the template directories have it. However, I've provided an example here that you can use. Obviously, if you don't use Linux and Clang, then you'll need to change it.

