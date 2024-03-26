#!bin/bash

make lib

if [ $? -eq 0 ]; then
  sudo mv libavl.so /usr/lib
  echo "INSTALLATION COMPLETED."
else
  echo "INSTALLATION FAILED."
fi
