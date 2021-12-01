# Linux-2.6-Scheduling-Policy
My implementation of a process scheduling policy on Linux v.2.6.38.1

## Part A - Syscalls implementations

You can find the implementation of two new system calls (get_period_params & set_period_params) in the Part A directory. A description of the implementation process
is included in the README.txt along with the edited files of the linux kernel. The kernel's dir structure has been kept so that it is easier for everyone to simply drag and drop
these files in the appropriate places to test things out.

A very quick and dirty test for these syscalls is also included in the directory.

## Part B - In development


## How to compile the kernel & load it

Once you've copied the appropriate files into the kernel's source code, simply cd into "Linux-2.6.38.1/" and run "make ARCH=i386 bzImage". An already generated image with the
new system calls can be found in "Part A/arch/x86/boot/bzImage".

You can load the new kernel into an emulator if you want to test it out safely. In this example I'm using Qemu. You can simply run :
$ qemu-system-i386 -hda original_kernel.img -append "root=/dev/hda" -kernel 
linux-2.6.38.1/arch/x86/boot/bzImage -curses

This will use the new edited kernel without a GUI.

## Source code for kernel 2.6.38.1
<a href="https://elixir.bootlin.com/linux/v2.6.38.1/source">Elixir bootlin link </a> for code lookup and kernel <a href="https://mirrors.edge.kernel.org/pub/linux/kernel/v2.6/"> v.2.6.38.1 </a> can be found here
