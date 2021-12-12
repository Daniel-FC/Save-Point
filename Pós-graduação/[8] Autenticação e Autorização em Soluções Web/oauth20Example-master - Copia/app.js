const express         =     require('express')
  , passport          =     require('passport')
  , cookieParser      =     require('cookie-parser')
  , session           =     require('express-session')
  , bodyParser        =     require('body-parser')
  , config            =     require('./configuration/config')
  , app               =     express();

var GoogleStrategy = require('passport-google-oauth20').Strategy;
var FacebookStrategy = require('passport-facebook').Strategy;

passport.use(new GoogleStrategy({
    clientID: config.api_key,
    clientSecret: config.api_secret,
    callbackURL: config.callback_url
  },
  function(accessToken, refreshToken, profile, done) {
    return done(null, profile);
  }
));

passport.use(new FacebookStrategy({
  clientID: '1533895810144978',
  clientSecret: '6b5eb17d8891a99bcc6f77fae8894ee0',
  callbackURL: "http://localhost:3000/auth/facebook/secrets"
},
function(accessToken, refreshToken, profile, done) {
  console.log(profile);
  if (profile) {
    return done(null, profile);
  }
  else {
    return done(null, false);
  }
}
));

// Passport session setup.
passport.serializeUser(function(user, done) {
  done(null, user);
});

passport.deserializeUser(function(obj, done) {
  done(null, obj);
});

app.set('views', __dirname + '/views');
app.set('view engine', 'ejs');
app.use(cookieParser());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(session({ secret: 'keyboard cat', resave: true, saveUninitialized: true }));
app.use(passport.initialize());
app.use(passport.session());
app.use(express.static(__dirname + '/public'));

app.get('/', function(req, res){
  res.render('index', { user: req.user });
});

app.get('/auth/google', passport.authenticate('google', { scope: ['profile'] }));

app.get('/auth/google/callback', 
  passport.authenticate('google',  { successRedirect : '/', failureRedirect: '/login' }),
  function(req, res) {
    res.redirect('/');
  }
);

app.get('/auth/facebook', passport.authenticate('facebook'));

app.get('/auth/facebook/secrets',
  passport.authenticate('facebook', { successRedirect : '/', failureRedirect: '/login' }),
  function(req, res) {
    // Successful authentication, redirect home.
    res.redirect('/secrets');
  });

app.get('/logout', function(req, res){
  req.logout();
  res.redirect('/');
});

app.listen(3000, () => console.log('Server up'));