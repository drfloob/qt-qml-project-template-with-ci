#!/bin/bash
# This script turns the 219 Design starter Qt project into a cookiecutter template

# Escapes literal {{ in the code. See https://jinja.palletsprojects.com/en/2.11.x/templates/#escaping
grep -l -R --binary-files=without-match "{{" src | xargs sed -i "s/{{/{{ '{{' }}/g" 

# Adds a custom project name and description to the readme
sed -i '1s/^/## {{ cookiecutter.project_name }}\n\n{{ cookiecutter.project_description }}\n\n/' README.md

# Modifies the copyright
git mv LICENSE.txt 219Design.LICENSE.txt
grep -l -E -R --binary-files=without-match 'Copyright \(c\) [0-9]{4}, 219 Design, LLC' src |\
    xargs sed -Ei -e "s/[0-9]{4}, 219 Design, LLC/{{ cookiecutter.year }}, {{ cookiecutter.full_name }}/g"\
    -e "s#https://www.219design.com#{{ cookiecutter.website }}#g"
find src/ -type f | xargs sed -i "/Software | Electrical | Mechanical | Product Design/d"

## Sets a custom namespace for the project
## Unfortunately sed doesn't play nicely with multi-line matches. Perl to the rescue
FILE_LIST=$(grep -l -E -R --binary-files=without-match '^namespace project' src)
echo "$FILE_LIST" | xargs -I ';;;' perl -0777 -i -pe "s/namespace project\n\{/{% set nslist = cookiecutter.cpp_namespace.split('.') %}\n{% for ns in nslist %}\nnamespace {{ ns }}\n{\n{% endfor %}/g" ';;;'
echo "$FILE_LIST" | xargs -I ';;;' sed -i "s#^} // namespace project#{% for ns in nslist %}\n} // namespace {{ ns }}\n{% endfor %}#g" ';;;'
grep -l -R --binary-files=without-match "project::" src | xargs sed -i "s/project::/{{ cookiecutter.cpp_namespace | replace('.', '::') }}::/g"

# Customizes the App.Desktop entry
sed -i -e "s/Name=.*/Name={{ cookiecutter.project_name }}/g"\
    -e "s/Comment=.*/Comment={{ cookiecutter.project_description }}/g"\
    tools/AppImage/app.desktop

# You can't assume cookiecutter will be run in the same git repo, so we have to set things up again
echo -e "git submodule add https://github.com/219-design/build_qt_binaries.git\n" >> tools/ci/provision.sh
rm -r build_qt_binaries

# Finally, moves the project folder to a cookiecutter namespace
mkdir "{{ cookiecutter.repo_name }}"
git mv -k * "{{ cookiecutter.repo_name }}"
git mv -k "{{ cookiecutter.repo_name }}"/cookiecutter* .
git mv .clang-format .gitattributes .github .gitignore .gitmodules .qmake.conf "{{ cookiecutter.repo_name }}"
