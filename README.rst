ITKTotalVariation
=================================

.. |CircleCI| image:: https://circleci.com/gh/InsightSoftwareConsortium/ITKTotalVariation.svg?style=shield
    :target: https://circleci.com/gh/InsightSoftwareConsortium/ITKTotalVariation

.. |TravisCI| image:: https://travis-ci.org/InsightSoftwareConsortium/ITKTotalVariation.svg?branch=master
    :target: https://travis-ci.org/InsightSoftwareConsortium/ITKTotalVariation

.. |AppVeyor| image:: https://img.shields.io/appveyor/ci/phcerdan/itktotalvariation.svg
    :target: https://ci.appveyor.com/project/phcerdan/itktotalvariation

=========== =========== ===========
   Linux      macOS       Windows
=========== =========== ===========
|CircleCI|  |TravisCI|  |AppVeyor|
=========== =========== ===========


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
   norm = 1
   dimensions_to_penalyze = [1,2,3]
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
