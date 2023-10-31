#include <iostream>
using namespace std;


// Abstract base class for image processors
class ImageProcessor {
public:
	virtual void loadImage(const string& filename) = 0;
	virtual void saveImage(const string& filename) = 0;
	virtual ~ImageProcessor() {}
};

// Concrete class for JPEG image processing
class JPEGImageProcessor : public ImageProcessor {
public:
	void loadImage(const string& filename) override {
		cout << "Loading JPEG image from " << filename << endl;
	}

	void saveImage(const string& filename) override {
		cout << "Saving image as JPEG to " << filename << endl;
	}
};

// Concrete class for PNG image processing
class PNGImageProcessor : public ImageProcessor {
public:
	void loadImage(const string& filename) override {
		cout << "Loading PNG image from " << filename << endl;
	}

	void saveImage(const string& filename) override {
		cout << "Saving image as PNG to " << filename << endl;
	}
};

// Factory Method to create image processors
class ImageProcessorFactory {
public:
	virtual ImageProcessor* createImageProcessor() = 0;
	virtual ~ImageProcessorFactory() {}
};

class JPEGImageProcessorFactory : public ImageProcessorFactory {
public:
	ImageProcessor* createImageProcessor() override {
		return new JPEGImageProcessor();
	}
};

class PNGImageProcessorFactory : public ImageProcessorFactory {
public:
	ImageProcessor* createImageProcessor() override {
		return new PNGImageProcessor();
	}
};

int main() {
	// Create a JPEG image processor using the factory
	ImageProcessorFactory* jpegFactory = new JPEGImageProcessorFactory();
	ImageProcessor* jpegProcessor = jpegFactory->createImageProcessor();

	// Load and save a JPEG image
	jpegProcessor->loadImage("image.jpg");
	jpegProcessor->saveImage("output.jpg");

	// Create a PNG image processor using the factory
	ImageProcessorFactory* pngFactory = new PNGImageProcessorFactory();
	ImageProcessor* pngProcessor = pngFactory->createImageProcessor();

	// Load and save a PNG image
	pngProcessor->loadImage("image.png");
	pngProcessor->saveImage("output.png");

	// Clean up
	delete jpegProcessor;
	delete jpegFactory;
	delete pngProcessor;
	delete pngFactory;

	return 0;
}