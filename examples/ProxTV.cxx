/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include <iostream>
#include <string>
#include "itkProxTV.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

template<typename ImageType>
void run( const std::string & inputImageFileName,
          const std::string & outputImageFileName,
          const double weight,
          const unsigned int maxIterations)
{
  using ReaderType = itk::ImageFileReader<ImageType>;
  auto reader = ReaderType::New();
  reader->SetFileName(inputImageFileName);

  using FilterType = itk::ProxTV< ImageType, ImageType >;
  typename FilterType::Pointer filter = FilterType::New();
  filter->SetInput(reader->GetOutput());
  filter->SetWeights(weight);
  filter->SetMaximumNumberOfIterations(maxIterations);
  // filter->Update();

  using WriterType = itk::ImageFileWriter<ImageType>;
  auto writer = WriterType::New();
  writer->SetInput(filter->GetOutput());
  writer->SetFileName(outputImageFileName);
  writer->Update();
}

int main(int argc, char *argv[])
{
  if( argc < 6 )
    {
    std::cerr << "Usage: " << argv[0];
    std::cerr << " inputImage";
    std::cerr << " outputImage";
    std::cerr << " dimension [2|3]";
    std::cerr << " pixeltype [float|double]";
    std::cerr << " weight";
    std::cerr << " maxIterations";
    std::cerr << std::endl;
    return EXIT_FAILURE;
    }

  const std::string inputImageFileName  = argv[1];
  const std::string outputImageFileName  = argv[2];
  const unsigned int dim = std::atoi(argv[3]);
  const std::string pixelType  = argv[4];
  const double weight  = std::atof(argv[5]);
  const unsigned int maxIterations  = std::atoi(argv[6]);
  if(!(dim == 2 || dim == 3))
    {
    std::cerr << "dim should be 2 or 3. Actual value: " << dim << std::endl;
    return EXIT_FAILURE;
    }

  if(!(pixelType != "float" || pixelType != "double"))
    {
    std::cerr << "pixel type should be float or double. Actual value: " << pixelType << std::endl;
    return EXIT_FAILURE;
    }
  if(dim == 2)
    {
    if(pixelType == "float")
      {
      using PixelType = float;
      using ImageType = itk::Image< PixelType, 2 >;
      run<ImageType>(inputImageFileName, outputImageFileName,
        weight, maxIterations);
      }
    else
      {
      using PixelType = double;
      using ImageType = itk::Image< PixelType, 2 >;
      run<ImageType>(inputImageFileName, outputImageFileName,
        weight, maxIterations);
      }
    }
  else
    {
    if(pixelType == "float")
      {
      using PixelType = float;
      using ImageType = itk::Image< PixelType, 3 >;
      run<ImageType>(inputImageFileName, outputImageFileName,
        weight, maxIterations);
      }
    else
      {
      using PixelType = double;
      using ImageType = itk::Image< PixelType, 3 >;
      run<ImageType>(inputImageFileName, outputImageFileName,
        weight, maxIterations);
      }
    }
}
