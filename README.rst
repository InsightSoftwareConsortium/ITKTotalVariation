ITKTotalVariation
=================================

.. image:: https://dev.azure.com/InsightSoftwareConsortium/ITKModules/_apis/build/status/itktotalvariation?branchName=master
    :target: https://dev.azure.com/InsightSoftwareConsortium/ITKModules/_build/latest?definitionId=8&branchName=master
    :alt:    Build Status

Overview
--------

TotalVariation algorithms, providing a wrap for the external project: https://github.com/albarji/proxTV

ITK is an open-source, cross-platform library that provides developers with an extensive suite of software tools for image analysis. Developed through extreme programming methodologies, ITK employs leading-edge algorithms for registering and segmenting multidimensional scientific images.

**Idea / Work in progress**

Not ready. The motivation is that Total Variation methods from proxTV are pretty effective denoisers.
If interested, there are python and matlab wraps available from https://github.com/albarji/proxTV .
If using the proxTV python package and python ITK, you can interconnect them:

.. code-block:: python

   import itk
   import prox_tv as ptv
   reader = itk.ImageFileReader.New(FileName=input_filename)
   reader.Update()
   image = reader.GetOutput()
   image_array = itk.GetArrayViewFromImage(image)
   lam = 20 # Lambda, denoise strength
   dimensions_to_penalyze = [1,2,3] # In all 3D directions
   norm = 1 # Norm used in algorithm, default is 1. || x_{i} - x_{i-1} ||_{norm}
   tv_array = ptv.tvgen(image_array, np.array([lam,lam,lam]), dimensions_to_penalyze, np.array([norm,norm,norm]))
   tv_array = np.ascontiguousarray(tv_array, dtype=image_array.dtype)
   modifiedImage = itk.GetImageViewFromArray(tv_array)
   itk.ImageFileWriter.New(Input=modifiedImage, FileName=output_filename).Update()

Example of 3D image denoised

Original:

.. image:: https://user-images.githubusercontent.com/3021667/38002434-9fc35d32-3232-11e8-8bfc-a7d9ce6888c7.png

Denoised:

.. image:: https://user-images.githubusercontent.com/3021667/38002451-b87bed62-3232-11e8-814b-50e8fb0f79cb.png

- [x] Add support for CMake to proxTV. Open PR: <https://github.com/albarji/proxTV/pull/38>
      And the branch in my fork: <https://github.com/phcerdan/proxTV/tree/cmake_support>
- [ ] Handle the external project. Choose between add_subdirectory, or ExternalProject_Add. Ask ITK.
- [ ] Do the actual wrapping with ITK classes.
- [ ] Profit and use TV methods in C++ with ITK.
