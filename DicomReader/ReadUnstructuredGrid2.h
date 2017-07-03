#pragma once
#define vtkRenderingCore_AUTOINIT 2(vtkRenderingOpenGL2, vtkInteractionStyle)

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkXMLGenericDataObjectReader.h>
#include <vtkUnstructuredGridReader.h>

///#include <vtkGenericDataObjectReader.h>



int execute() {


	std::string inputFilename = "C:/DicomReader/DicomReader/2file.vtk";

	// Get all data from the file
	vtkSmartPointer<vtkUnstructuredGridReader> reader =
		vtkSmartPointer<vtkUnstructuredGridReader>::New();
	reader->SetFileName(inputFilename.c_str());
	reader->Update();

	// All of the standard data types can be checked and obtained like this:
	if (vtkPolyData::SafeDownCast(reader->GetOutput()))	{
		std::cout << "File is a polydata" << std::endl;
	}
	else if (vtkUnstructuredGrid::SafeDownCast(reader->GetOutput())){
		std::cout << "File is an unstructured grid" << std::endl;
	}
	
	if(reader->IsFileUnstructuredGrid())
		std::cout<<"si\n";
	else
		std::cout << "no\n";

	// Visualize
	vtkSmartPointer<vtkDataSetMapper> mapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	mapper->SetInputConnection(reader->GetOutputPort());

	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->SetSize(1080,720);
	renderWindow->AddRenderer(renderer);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);

	renderer->AddActor(actor);
	renderer->SetBackground(40/255, 50/255, 34/255); 

	renderWindow->Render();
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;

	
}