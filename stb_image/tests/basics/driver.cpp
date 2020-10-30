#include <iostream>
//
#include <stb_image.h>

int main(int argc, char* argv[]) {
  using namespace std;

  int image_width, image_height, image_channels;

  stbi_set_flip_vertically_on_load(true);

  unsigned char* image_data =
      stbi_load(argv[1], &image_width, &image_height, &image_channels, 0);

  if (image_data) {
    cout << "resolution = " << image_width << " x " << image_height << " x "
         << image_channels << "\n";
  } else {
    throw runtime_error("Could not load the given image!\n"s + argv[1]);
  }
}