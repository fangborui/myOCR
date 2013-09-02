#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include "OCRMask.h"

class ImageWidget;
class QTextEdit;
class AbbyyOCR;
class CubeWidget;
class ParamWidget;
class ImageProcess;
class TesseractOCR;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();
private slots:
	void openImageFile();
	void saveImageFile();
	void recognizeText();

	void showParamWidget();
	void processImage();

	void enableMasks();
	void saveMasks();
	void loadMasks();
	void clearMasks();

	void enableMesure();
	void enableChinese();

	void showCube();
private:
	void buildUI();
	//user interface components
	ImageWidget* imageWidget;
	CubeWidget* cubeWidget;
	ParamWidget* paramWidget;
	QTextEdit* textEdit;

	QMenu* menuFile;
	QMenu* menuImage;
	QMenu* menuHelp;

	QToolBar* toolBarFile;
	QToolBar* toolBarImage;
	
	QAction* actionOpenImage;
	QAction* actionSaveImage;
	QAction* actionRecognizeText;
	QAction* actionProcessImage;
	QAction* actionEnableMasks;
	QAction* actionSaveMasks;
	QAction* actionLoadMasks;
	QAction* actionClearMasks;
	QAction* actionEnableMesure;
	QAction* actionEnableChinese;
	QAction* actionShowCube;
	QAction* actionAbout;

	//internal variables
	AbbyyOCR* mAbbyyOCR;
	TesseractOCR* mTesseractOCR;
	ImageProcess* mImageProcess;

	QVector<OCRMask>* mOCRMasks;
};

#endif //MAINWINDOW_H