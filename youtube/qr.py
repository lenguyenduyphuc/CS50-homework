import qrcode

img = qrcode.make("https://www.youtube.com/watch?v=EHi0RDZ31VA&t=64s")
img.save("qr.png", "PNG")
