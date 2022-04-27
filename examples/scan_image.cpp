// #include <Magick++.h>
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

    // int width  = magick.columns(); // extract dimensions
    // int height = magick.rows();

    // Magick::Blob blob; // extract the raw data
    // magick.modifyImage();
    // magick.write(&blob, "GRAY", 8);
    // const void *raw = blob.data();
    const void *raw = buffer.get();

    // wrap image data
    Image image(width, height, "Y800", raw, width * height);

    // scan the image for barcodes
    int n = scanner.scan(image);

    // extract results
    for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) 
     {
        cout << "decoded " << symbol->get_type_name() << " symbol \"" << symbol->get_data() << '"' << endl;
    }

    // clean up
    image.set_data(NULL, 0);

    return (0);
}
