extern "C" {
#include <stb_image.h>
}
//
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) {
  using namespace std;

  int image_width, image_height, image_channels;

  stbi_set_flip_vertically_on_load(true);

  unsigned char* image_data =
      stbi_load(argv[1], &image_width, &image_height, &image_channels, 0);

  if (!image_data) {
    cerr << "Could not load the image!\n" << flush;
    return -1;
  }

  cout << "resolution = " << image_width << " x " << image_height << " x "
       << image_channels << "\n"
       << flush;
}