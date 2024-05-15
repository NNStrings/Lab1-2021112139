# Lab1-2021112139

### install

```bash
cd ~/
git clone https://github.com/google/googletest.git
cd googletest
mkdir build && cd build
cmake -DCMAKE_CXX_STANDARD=17 ..
make
sudo make install

cd ..
cp googletest/include/gtest your_project_folder/test/include/
cp googlemock/include/gmock your_project_folder/test/include/gmock
cp build/lib your_project_folder/test/lib
```