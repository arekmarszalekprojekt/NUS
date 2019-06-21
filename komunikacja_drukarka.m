drukarka = serial ( '/dev/ttyUSB4' )
drukarka.BaudRate = 115200
drukarka.Terminator = 'CR/LF'
fopen(drukarka)