from flask import Flask, jsonify, request #import objects from the Flask model
app = Flask(__name__) #define app using Flask


students = [{'roll': 1 ,'First_name' : 'ABC','Middle_name':'XYZ','Last_name' : 'PQR','Contact':'0000000000','Address':'Pune','Qualification':'BSc','Course':'MSc'},
            {'roll': 2 ,'First_name' : 'Gaurav','Middle_name':'XYZ','Last_name' : 'PQR','Contact':'0000000000','Address':'Pune','Qualification':'BSc','Course':'MSc'},
            {'roll': 3 ,'First_name' : 'Prasad','Middle_name':'XYZ','Last_name' : 'PQR','Contact':'0000000000','Address':'Pune','Qualification':'BSc','Course':'MSc'},
            {'roll': 4 ,'First_name' : 'Saroj','Middle_name':'XYZ','Last_name' : 'PQR','Contact':'0000000000','Address':'Pune','Qualification':'BSc','Course':'MSc'}]

@app.route('/', methods=['GET'])
def test():
	return jsonify({'message' : 'Welcome to students Database!!!!!:>'})


@app.route('/stud', methods=['GET'])
def returnAll():
	return jsonify({'students' : students})


@app.route('/stud/<string:roll>', methods=['GET'])
def returnOne(roll):
	studs = [student for student in students if student['roll'] == int(roll)]
	return jsonify({'student' : studs[0]})


@app.route('/stud', methods=['POST'])
def addOne():
	print(request.json)
	student = {'roll': request.json['roll'], 'First_name' : request.json['First_name'],'Middle_name' : request.json['Middle_name'],'Last_name': request.json['Last_name'],'Contact': request.json['Contact'],'Address': request.json['Address'],'Qualification': request.json['Qualification'],'Course': request.json['Course']}

	students.append(student)
	return jsonify({'msg': 'Student data has been added.!'})


@app.route('/stud/<string:roll>', methods=['PUT'])
def editOne(roll):
	studs = [student for student in students if student['roll'] == int(roll)]
	studs[0]['First_name'] = request.json['First_name']
	studs[0]['Middle_name'] = request.json['Middle_name']
	studs[0]['Last_name'] = request.json['Last_name']
	studs[0]['Contact'] = request.json['Contact']
	studs[0]['Address'] = request.json['Address']
	studs[0]['Qualification'] = request.json['Qualification']
	studs[0]['Course'] = request.json['Course']
	return jsonify({'student' : studs[0]})


@app.route('/stud/<string:roll>', methods=['DELETE'])
def removeOne(roll):
	stud = [student for student in students if student['roll'] == int(roll)]
	students.remove(stud[0])
	return jsonify({'students' : students})

if __name__ == '__main__':
	app.run(debug=True, port=3000) #run app on port 8777 in debug mode
