// #include <Magick++.h>
#include <stdlib.h>
#include <memory>
#include <iostream>
#include <zbar.h>
#include <stb_image.h>
#define STR(s) #s

using namespace std;
using namespace zbar;

int main(int argc, char **argv)
{
    if (argc < 2)
	return (1);

#ifdef MAGICK_HOME
    // http://www.imagemagick.org/Magick++/
    //    under Windows it is necessary to initialize the ImageMagick
    //    library prior to using the Magick++ library
    Magick::InitializeMagick(MAGICK_HOME);
#endif

    // create a reader
    ImageScanner scanner;

    // configure the reader
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

    const auto& filePath = argv[1];

    // obtain image data
    // Magick::Image magick(argv[1]); // read an image file
    int width, height, channels;
		std::unique_ptr<stbi_uc, void(*)(void*)> buffer(stbi_load(argv[1], &width, &height, &channels, 4), stbi_image_free);
		if (buffer == nullptr) {
			std::cerr << "Failed to read image: " << filePath << "\n";
			return -1;
		}
        else
        {
            std::cout << "Loaded image: " << filePath << std::endl;
            std::cout << "width: " << width << " height: " << height << " channels: " << channels << std::endl;
        }

    // int width  = magick.columns(); // extract dimensions
    // int height = magick.rows();

    // Magick::Blob blob; // extract the raw data
    // magick.modifyImage();
    // magick.write(&blob, "GRAY", 8);
    // const void *raw = blob.data();
    unsigned char *raw = buffer.get();
    std::cout << "buff: " << raw << std::endl;

    // convert to grayscale
    // Convert the input image to gray
    size_t img_size = width * height * channels;
    int gray_channels = channels == 4 ? 2 : 1;
    size_t gray_img_size = width * height * gray_channels;

    unsigned char *gray_img = (unsigned char *)malloc(gray_img_size);
    if(gray_img == NULL) {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    unsigned char *p = raw;
    for(unsigned char *pg = gray_img; p != raw + img_size; p += channels, pg += gray_channels) {
        uint8_t val = (uint8_t)((*p + *(p + 1) + *(p + 2))/3.0);
         *pg = (uint8_t)((*p + *(p + 1) + *(p + 2))/3.0);
         if(channels == 4) {
             *(pg + 1) = *(p + 3);
         }
     }
  std::cout << "Passing point to Image class" << std::endl;
    // wrap image data
    Image image(width, height, "Y800", gray_img, width * height);

    std::cout << "Calling scanner.scan" << std::endl;
    // scan the image for barcodes
    int n = scanner.scan(image);

    std::cout << "Scanner return code: " << n << std::endl;

    // extract results
    for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) 
     {
        cout << "decoded " << symbol->get_type_name() << " symbol \"" << symbol->get_data() << '"' << endl;
    }

    // clean up
    image.set_data(NULL, 0);

    return (0);
}
