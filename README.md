<h1 align="center">
    build2 Packages for stb Libraries
</h1>

<p align="center">
    This project builds and defines the build2 packages for the
    <a href="https://github.com/nothings/stb">stb</a> libraries (single-file public domain or MIT licensed libraries for C/C++).
</p>

<p align="center">
    <a href="https://github.com/nothings/stb">
        <img src="https://img.shields.io/website/https/github.com/nothings/stb.svg?down_message=offline&label=Official&style=for-the-badge&up_color=blue&up_message=online">
    </a>
    <a href="https://github.com/build2-packaging/stb">
        <img src="https://img.shields.io/website/https/github.com/build2-packaging/stb.svg?down_message=offline&label=build2&style=for-the-badge&up_color=blue&up_message=online">
    </a>
    <a href="https://cppget.org/?packages=stb">
        <img src="https://img.shields.io/website/https/cppget.org/stb.svg?down_message=online&down_color=blue&label=cppget.org&style=for-the-badge&up_color=blue&up_message=online">
    </a>
    <a href="https://queue.cppget.org/?packages=stb">
        <img src="https://img.shields.io/website/https/queue.cppget.org/stb.svg?down_message=check&down_color=blue&label=queue.cppget.org&style=for-the-badge&up_color=blue&up_message=check">
    </a>
</p>

## Usage
Make sure to add an appropriate section, like `alpha` or `stable`, of the `cppget.org` repository to your project's `repositories.manifest` to be able to fetch required packages.

    :
    role: prerequisite
    location: https://pkg.cppget.org/1/stable
    # trust: ...

If `cppget.org` is not an option then add this Git repository itself instead as a prerequisite.

    :
    role: prerequisite
    location: https://github.com/build2-packaging/stb.git

Add the respective dependency in your project's `manifest` file to make the required packages available for import.

    depends: stb_c_lexer ^0.12.0
    depends: stb_connected_components ^0.96.0
    depends: stb_divide ^0.94.0
    depends: stb_ds ^0.67.0
    depends: stb_dxt ^1.12.0
    depends: stb_easy_font ^1.1.0
    depends: stb_herringbone_wang_tile ^0.7.0
    depends: stb_hexwave ^0.5.0
    depends: stb_image ^2.28.0
    depends: stb_image_resize ^0.97.0
    depends: stb_image_write ^1.16.0
    depends: stb_include ^0.2.0
    depends: stb_leakcheck ^0.6.0
    depends: stb_perlin ^0.5.0
    depends: stb_rect_pack ^1.1.0
    depends: stb_sprintf ^1.10.0
    depends: stb_textedit ^1.14.0
    depends: stb_tilemap_editor ^0.42.0
    depends: stb_truetype ^1.26.0
    depends: stb_vorbis ^1.22.0
    depends: stb_voxel_render ^0.89.0

Libraries can then simply be imported by the following declarations in a `buildfile`.

    import stb_c_lexer = stb_c_lexer%lib{stb_c_lexer}
    import stb_connected_components = stb_connected_components%lib{stb_connected_components}
    import stb_divide = stb_divide%lib{stb_divide}
    import stb_ds = stb_ds%lib{stb_ds}
    import stb_dxt = stb_dxt%lib{stb_dxt}
    import stb_easy_font = stb_easy_font%lib{stb_easy_font}
    import stb_herringbone_wang_tile = stb_herringbone_wang_tile%lib{stb_herringbone_wang_tile}
    import stb_hexwave = stb_hexwave%lib{stb_hexwave}
    import stb_image = stb_image%lib{stb_image}
    import stb_image_resize = stb_image_resize%lib{stb_image_resize}
    import stb_image_write = stb_image_write%lib{stb_image_write}
    import stb_include = stb_include%lib{stb_include}
    import stb_leakcheck = stb_leakcheck%lib{stb_leakcheck}
    import stb_perlin = stb_perlin%lib{stb_perlin}
    import stb_rect_pack = stb_rect_pack%lib{stb_rect_pack}
    import stb_sprintf = stb_sprintf%lib{stb_sprintf}
    import stb_textedit = stb_textedit%lib{stb_textedit}
    import stb_tilemap_editor = stb_tilemap_editor%lib{stb_tilemap_editor}
    import stb_truetype = stb_truetype%lib{stb_truetype}
    import stb_vorbis = stb_vorbis%lib{stb_vorbis}
    import stb_voxel_render = stb_voxel_render%lib{stb_voxel_render}

## Configuration
There are no configuration options vailable.

## Issues and Notes
- Each package provides its own version. That makes updates to new specific versions and the support of older versions much harder.
- When compiling C code, for some libraries `-lm` needs to added manually for static builds. This might be a bug in build2.
- Working on these packages is quite generic. You should use in-place shell programming to add features to all packages at once.
```fish
for x in stb*
    echo $x:
    ...
end
```
- Tests with file I/O fail on Emscripten-based target configurations.
- `stb_herringbone_wang_tile` and `stb_sprintf` exhibit errors for a few other target configurations.
- For `stb_image_write`, there are still some unused-function warnings.
- Other warnings are not disabled. They show potential flaws in the upstream libraries.
- Precompiled targets are not supported as all the libraries provide too many configuration macros.
- The documentation of each library can be found in their respective header file itself.

## Contributing
Thanks in advance for your help and contribution to keep these packages up-to-date.
For now, please, file an issue on [GitHub](https://github.com/build2-packaging/miniz/issues) for everything that is not described below.

### Recommend Updating Version
Please, file an issue on [GitHub](https://github.com/build2-packaging/miniz/issues) with the new recommended version.

### Update Version by Pull Request
1. Fork the repository on [GitHub](https://github.com/build2-packaging/miniz) and clone it to your local machine.
2. Run `git submodule init` and `git submodule update` to get the current upstream directory.
3. Inside the `upstream` directory, checkout the new commit.
4. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
5. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
6. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
7. Run `bdep ci` and test for errors.
8. If everything works fine, make a pull request on GitHub and write down the `bdep ci` link to your CI tests.
9. After a successful pull request, we will run the appropriate commands to publish a new package version.

### Update Version Directly if You Have Permissions
1. Inside the `upstream` directory, checkout the new commit.
2. If needed, change source files, `buildfiles`, and symbolic links accordingly to create a working build2 package. Make sure not to directly depend on the upstream directory inside the build system but use symbolic links instead.
3. Update library version in `manifest` file if it has changed or add package update by using `+n` for the `n`-th update.
4. Make an appropriate commit message by using imperative mood and a capital letter at the start and push the new commit to the `master` branch.
5. Run `bdep ci` and test for errors and warnings.
6. When successful, run `bdep release --tag --push` to push new tag version to repository.
7. Run `bdep publish` to publish the package to [cppget.org](https://cppget.org).
