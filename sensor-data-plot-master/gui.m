function varargout = Example1(varargin)
% EXAMPLE1 MATLAB code for Example1.fig
%      EXAMPLE1, by itself, creates a new EXAMPLE1 or raises the existing
%      singleton*.
%
%      H = EXAMPLE1 returns the handle to a new EXAMPLE1 or the handle to
%      the existing singleton*.
%
%      EXAMPLE1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EXAMPLE1.M with the given input arguments.
%
%      EXAMPLE1('Property','Value',...) creates a new EXAMPLE1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Example1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Example1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Example1

% Last Modified by GUIDE v2.5 15-Mar-2015 23:17:32

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Example1_OpeningFcn, ...
                   'gui_OutputFcn',  @Example1_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Example1 is made visible.
function Example1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Example1 (see VARARGIN)

% Choose default command line output for Example1
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Example1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);
delete(instrfind({'Port'},{'COM4'}))
clear a;
global a;
a = arduino('COM8');
a.pinMode(13, 'output');


% --- Outputs from this function are returned to the command line.
function varargout = Example1_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in turn_on_button.
function turn_on_button_Callback(hObject, eventdata, handles)
% hObject    handle to turn_on_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global a;
a.digitalWrite(13,1);


% --- Executes on button press in turn_off_button.
function turn_off_button_Callback(hObject, eventdata, handles)
% hObject    handle to turn_off_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global a;
a.digitalWrite(13,0);


% --- Executes on button press in read_button.
function read_button_Callback(hObject, eventdata, handles)
% hObject    handle to read_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global k a
x=0;

for k=1:1:handles.xSamples
    b=a.analogRead(0);
    x=[x,b];
    plot(x,'LineWidth',2); grid on;
    axis([0 handles.xSamples 0 500]);
    pause(0.01);
end


function edit_text_samples_Callback(hObject, eventdata, handles)
% hObject    handle to edit_text_samples (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_text_samples as text
%        str2double(get(hObject,'String')) returns contents of edit_text_samples as a double
handles.data1=get(hObject,'String');
handles.xSamples=str2double(handles.data1);
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function edit_text_samples_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_text_samples (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
