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

#include "itkProxTVImageFilter.h"
#include "itkImageFileReader.h"
#include "itkCastImageFilter.h"
#include "itkImageFileWriter.h"
#include "itkImageIOBase.h"

template<typename ImageType>
int run( const std::string & inputImageFileName,
          const std::string & outputImageFileName,
          const double weight,
          const unsigned int maxIterations)
{
  using TVImageType = itk::Image< double, ImageType::ImageDimension >;
  using ReaderType = itk::ImageFileReader< TVImageType >;
  auto reader = ReaderType::New();
  reader->SetFileName(inputImageFileName);

  using FilterType = itk::ProxTVImageFilter< TVImageType, TVImageType >;
  typename FilterType::Pointer filter = FilterType::New();
  filter->SetInput(reader->GetOutput());
  filter->SetWeights(weight);
  filter->SetMaximumNumberOfIterations(maxIterations);
  filter->Update();

  using CastFilterType = itk::CastImageFilter< TVImageType, ImageType >;
  typename CastFilterType::Pointer castFilter = CastFilterType::New();
  castFilter->SetInput( filter->GetOutput() );

  using WriterType = itk::ImageFileWriter<ImageType>;
  auto writer = WriterType::New();
  writer->SetInput(castFilter->GetOutput());
  writer->SetFileName(outputImageFileName);
  writer->Update();

  return EXIT_SUCCESS;
}

template<typename TPixel>
int runWithDimension( const std::string & inputImageFileName,
          const std::string & outputImageFileName,
          const double weight,
          const unsigned int maxIterations,
          const unsigned int dimension )
{
  using PixelType = TPixel;
  switch( dimension )
    {
  case 2:
      {
      using ImageType = itk::Image<PixelType, 2>;
      return run<ImageType>(inputImageFileName, outputImageFileName,
        weight, maxIterations);
      }
  case 3:
      {
      using ImageType = itk::Image<PixelType, 3>;
      return run<ImageType>(inputImageFileName, outputImageFileName,
        weight, maxIterations);
      }
  default:
    std::cerr << "Unsupported dimension: " << dimension << std::endl;
    return EXIT_FAILURE;
    }
  return EXIT_FAILURE;
}

int main(int argc, char *argv[])
{
  if( argc < 6 )
    {
    std::cerr << "Usage: " << argv[0];
    std::cerr << " inputImage";
    std::cerr << " outputImage";
    std::cerr << " weight";
    std::cerr << " maxIterations";
    std::cerr << std::endl;
    return EXIT_FAILURE;
    }

  const std::string inputImageFileName  = argv[1];
  const std::string outputImageFileName  = argv[2];
  const double weight  = std::atof(argv[3]);
  const unsigned int maxIterations  = std::atoi(argv[4]);

  itk::ImageIOBase::Pointer imageIO =
  itk::ImageIOFactory::CreateImageIO(
    inputImageFileName.c_str(),
    itk::ImageIOFactory::ReadMode );

  imageIO->SetFileName( inputImageFileName );
  imageIO->ReadImageInformation();

  using IOComponentType = itk::ImageIOBase::IOComponentType;
  const IOComponentType componentType = imageIO->GetComponentType();

  const unsigned int imageDimension = imageIO->GetNumberOfDimensions();

  switch( componentType )
    {
    case itk::ImageIOBase::UCHAR:
      {
      using PixelType = unsigned char;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    case itk::ImageIOBase::CHAR:
      {
      using PixelType = signed char;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    case itk::ImageIOBase::USHORT:
      {
      using PixelType = unsigned short;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    case itk::ImageIOBase::SHORT:
      {
      using PixelType = short;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    case itk::ImageIOBase::UINT:
      {
      using PixelType = unsigned int;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    case itk::ImageIOBase::INT:
      {
      using PixelType = int;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    case itk::ImageIOBase::ULONG:
      {
      using PixelType = unsigned long;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    case itk::ImageIOBase::LONG:
      {
      using PixelType = long;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    case itk::ImageIOBase::FLOAT:
      {
      using PixelType = float;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    case itk::ImageIOBase::DOUBLE:
      {
      using PixelType = double;
      return runWithDimension<PixelType>(inputImageFileName, outputImageFileName,
        weight, maxIterations, imageDimension);
      }

    default:
    case itk::ImageIOBase::UNKNOWNCOMPONENTTYPE:
      std::cerr << "Unknown and unsupported component type!" << std::endl;
      return EXIT_FAILURE;

    }
  return EXIT_FAILURE;
}
