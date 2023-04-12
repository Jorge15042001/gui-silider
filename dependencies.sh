

mkdir -p ./libs/
mkdir -p ./libs/libs

# download gtkmm 4.9
curl https://mirror2.sandyriver.net/pub/software/gnome/sources/gtkmm/4.9/gtkmm-4.9.2.tar.xz --output /tmp/gtkmm-4
mkdir -p ./libs/gtkmm
tar -xf /tmp/gtkmm-4 -C libs/gtkmm  --strip-components=1

cd ./libs/gtkmm/
mkdir -p ./build_gtkmm

meson setup --prefix $(pwd)/../libs ./build_gtkmm .

cd ./build_gtkmm
ninja
ninja install
