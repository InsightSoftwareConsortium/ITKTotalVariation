ITKTotalVariation
=================

.. image:: https://dev.azure.com/InsightSoftwareConsortium/ITKModules/_apis/build/status/InsightSoftwareConsortium.ITKTotalVariation?branchName=master
    :target: https://dev.azure.com/InsightSoftwareConsortium/ITKModules/_build/latest?definitionId=21&branchName=master
    :alt:    Build Status

.. image:: https://img.shields.io/badge/License-Apache%202.0-blue.svg
    :target: https://github.com/InsightSoftwareConsortium/ITKTotalVariation/blob/master/LICENSE
    :alt:    License

Overview
--------

TotalVariation algorithms. itkProxTVImageFilter provides a wrap for the external project proxTV: https://github.com/albarji/proxTV

ITK provides wrapping for Windows, macOS and Linux:

.. code-block:: python

   import itk
   Dimension = 3
   I = itk.Image[itk.F, Dimension]
   reader = itk.ImageFileReader[I].New(FileName=file_name)
   reader.Update()
   image = reader.GetOutput()
   tv = itk.ProxTVImageFilter[I, I].New()
   tv.SetInput(image)
   tv.SetMaximumNumberOfIterations(10)
   tv.SetWeights(100)
   tv.Update()
   output_file_name="/tmp/tvout.nrrd"
   itk.imwrite(tv.GetOutput(), output_file_name)

Examples of 3D image denoised

Original:

.. image:: https://user-images.githubusercontent.com/3021667/55841022-95524a00-5afb-11e9-92f1-3743c4ddbf4c.png

TotalVariation denoised:

.. image:: https://user-images.githubusercontent.com/3021667/55841021-94b9b380-5afb-11e9-9961-37072274bd68.png

Original:

.. image:: https://user-images.githubusercontent.com/3021667/38002434-9fc35d32-3232-11e8-8bfc-a7d9ce6888c7.png

Denoised:

.. image:: https://user-images.githubusercontent.com/3021667/38002451-b87bed62-3232-11e8-814b-50e8fb0f79cb.png

- [x] Add support for CMake to proxTV. Open PR: <https://github.com/albarji/proxTV/pull/38>
      And the branch in my fork: <https://github.com/phcerdan/proxTV/tree/cmake_support>
- [x] Uses CMake FetchContent to download the third party proxTV.
- [x] Do the actual wrapping with ITK classes.
- [x] Check that python module: itk-totalvariation works for:
   - [x] Linux
   - [x] Mac
   - [ ] Windows
- [x] Profit and use TV methods in C++ with ITK.

Maintainers:
- Pablo Hernandez-Cerdan @phcerdan https://github.com/phcerdan


License
-------

This software is distributed under the Apache 2.0 license. Please see the
*LICENSE* file for details.

